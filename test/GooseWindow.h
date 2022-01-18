/*
 * GooseWindow.h
 *
 *  Created on: 18 окт. 2021 г.
 *      Author: Семен Беляев
 */

#ifndef GOOSEWINDOW_H_
#define GOOSEWINDOW_H_

#include "Window.h"
#include "Texture.h"
#include "LayerTexture.h"

class GooseWindow final: public Window
{
private:
	Texture _goose;
	Texture _cloud;
	Texture _eagle;
	Texture _background;
	LayerTexture _mountains;
	LayerTexture _grass;
	Texture _sun;
	LayerTexture _stars;
	double ex,ey;
	double x,y,phase;
	static constexpr int GOOSE_WINDOW_WIDTH=800;
	static constexpr int GOOSE_WINDOW_HEIGHT=600;

	SDL_FRect clouds[6]{
		{128.0,200.0,128.0,64.0},
		{356.0,430.0,192.0,70.0},
		{500.0,340.0,160.0,90.0},
		{50.0,80.0,384.0,192.0},
		{420.0,279.0,480.0,200.0},
		{220.0,330.0,600.0,300.0},

			};


public:
	GooseWindow();
	virtual ~GooseWindow()=default;

	virtual void render() override;
	virtual void handle_keys(const Uint8 *keys) override;
	virtual void update() override;
};


#endif /* GOOSEWINDOW_H_ */
