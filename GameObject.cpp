#include "GameObject.h"

GameObject::GameObject(int posX, int posY, int sizeX, int sizeY)
{
	posX_ = posX;
	posY_ = posY;
	sizeX_ = sizeX;
	sizeY_ = sizeY;
	body_ = new char*[sizeY_];
	for (int i = 0; i < sizeY_; i++)
		body_[i] = new char[sizeX_];
}
GameObject::~GameObject()
{
	for (int i = 0; i < sizeY_; i++)
		delete[] body_[i];
	delete[] body_;
}