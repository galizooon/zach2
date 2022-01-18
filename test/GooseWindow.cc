/*
 * GooseWindow.cc
 *
 *  Created on: 18 окт. 2021 г.
 *      Author: Семен Беляев
 */
#include "GooseWindow.h"
#include <cmath>
GooseWindow::GooseWindow() :Window(GOOSE_WINDOW_WIDTH,GOOSE_WINDOW_HEIGHT),
_goose(_renderer, "1.png"),
_cloud(_renderer,"3.png"),
_background(_renderer,"4.png"),
_mountains(_renderer,"5.png",2.0),
_grass(_renderer,"6.png",6.0),
_eagle(_renderer,"2.png"),
_sun(_renderer,"7.png"),
_stars(_renderer,"8.png",1.0)
{
SDL_SetWindowTitle(_window.get(),"Gooses");
x=50;
y=0.0;
ex=0;
ey=0;
phase=0.0;
}

void GooseWindow::render()
{
	SDL_SetRenderDrawColor(_renderer.get(),63,192,255,255);
	//SDL_RenderClear(_renderer.get());
	_background.draw(0,0);
	_stars.draw(0,0,width(),_stars.height());
	_sun.draw(100,200);
	_mountains.draw(0,320, width(),_mountains.height());
	_grass.draw(0,480,width(),_grass.height());
	unsigned i=0;
	for(;i<3;++i)
		_cloud.draw(clouds[i]);
	_goose.draw(x,y,(sin(phase)+cos(phase))/2*180/3.1415);
	_goose.draw(x,y,(sin(phase)+cos(phase))/3*180/3.1415);
	_goose.draw(x,y,(sin(phase)+cos(phase))/2*90/3.1415);
	_goose.draw(x,y,(sin(phase)+cos(phase))/2*180/2.1415);
	_eagle.draw(ex,ey,50,50);

	for(;i<6;++i)
			_cloud.draw(clouds[i]);
}
void GooseWindow::handle_keys(const Uint8 *keys) {

	if (keys[SDL_SCANCODE_RIGHT])
		ex += 4;
			if (keys[SDL_SCANCODE_LEFT])
				ex -= 4;


			if (keys[SDL_SCANCODE_DOWN])
				ey += 4;


			if (keys[SDL_SCANCODE_UP])
				ey -= 4;

}

void GooseWindow::update()
{
auto pi=acos(-1.0);
phase+=pi/90.0;
x+=3;
if(x>=width())
	x=-_goose.width();
y=height()/2*(1+0.3*sin(phase))-height()/4;
for(unsigned i=0;i<6;++i){
	clouds[i].x-=clouds[i].w/32;
	if(clouds[i].x<=-clouds[i].w) clouds[i].x=width();
}
_mountains.update();
_grass.update();
_stars.update();
}

