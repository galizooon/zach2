/*
 * LayerTexture.h
 *
 *  Created on: 20 окт. 2021 г.
 *      Author: Семен Беляев
 */

#ifndef LAYERTEXTURE_H_
#define LAYERTEXTURE_H_

#include "Texture.h"

class LayerTexture: public Texture {
protected:
	double _speed{};
	double _offset{};


public:
	LayerTexture(std::shared_ptr<SDL_Renderer> &renderer, const char *filename, double spd);
	virtual ~LayerTexture() = default;

	virtual void draw(int x, int y, int w, int h) override;
	//virtual void draw(int x, int y)=delete;
	//virtual void draw(double x, double y, double angle)=delete;
//	virtual void draw(const SDL_FRect &r)=delete;
	virtual void update();
};

#endif /* LAYERTEXTURE_H_ */
