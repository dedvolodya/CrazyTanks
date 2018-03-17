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
GameObject::GameObject(const GameObject& obj) {
	if (this == &obj)
		return;

	for (int i = 0; i < sizeY_; i++)
		delete[] body_[i];
	delete[] body_;

	body_ = new char*[obj.sizeY_];
	for (int i = 0; i < obj.sizeY_; i++)
		body_[i] = new char[obj.sizeX_];

	sizeX_ = obj.sizeX_;
	sizeY_ = obj.sizeY_;
	posX_ = obj.posX_;
	posY_ = obj.posY_;

	for (int i = 0; i < sizeY_; i++)
		for (int j = 0; j < sizeX_; j++)
			body_[i][j] = obj.body_[i][j];
}

GameObject& GameObject::operator=(const GameObject& obj) {
	if (this == &obj)
		return *this;
	
	for (int i = 0; i < sizeY_; i++)
		delete[] body_[i];
	delete[] body_;

	body_ = new char*[obj.sizeY_];
	for (int i = 0; i < obj.sizeY_; i++)
		body_[i] = new char[obj.sizeX_];

	sizeX_ = obj.sizeX_;
	sizeY_ = obj.sizeY_;
	posX_ = obj.posX_;
	posY_ = obj.posY_;

	for (int i = 0; i < sizeY_; i++)
		for (int j = 0; j < sizeX_; j++)
			body_[i][j] = obj.body_[i][j];
	return *this;
}

GameObject::~GameObject()
{
	for (int i = 0; i < sizeY_; i++)
		delete[] body_[i];
	delete[] body_;
}