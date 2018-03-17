#include "Wall.h"


Wall::Wall(int posX, int posY, int size, Placing placing) :
	 GameObject(posX, posY,0,0)
{
	if (placing == Wall::GORIZONTAL) {
		sizeX_ = size;
		sizeY_ = 1;
	}
	else {
		sizeX_ = 1;
		sizeY_ = size;
	}

	body_ = new char*[sizeY_];
	for (int i = 0; i < sizeY_; i++)
		body_[i] = new char[sizeX_];

	for (int i = 0; i < sizeY_; i++)
		for (int j = 0; j < sizeX_; j++)
			body_[i][j] = 'N';
}


Wall::~Wall()
{
}
