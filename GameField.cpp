#include "GameField.h"


GameField::GameField(int sizeX,int sizeY)
{
	field_ = new char*[sizeY];
	for (int i = 0; i < sizeY; i++)
		field_[i] = new char[sizeX];

	for (int i = 0; i < sizeY; i++)
		for (int j = 0; j < sizeX; j++)
			field_[i][j] = ' ';

	sizeX_ = sizeX;
	sizeY_ = sizeY;
}
GameField::~GameField() {
	for (int i = 0; i < sizeY_; i++)
		delete[] field_[i];
	delete[] field_;
}
void GameField::print() const {
	system("cls");
	for (int i = 0; i < sizeY_; i++) {
		for (int j = 0; j < sizeX_; j++)
			std::cout << field_[i][j];
		std::cout << std::endl;
	}
}
void GameField::deleteObject(const GameObject& obj) {
	for (int i = obj.posY_; i < obj.posY_ + obj.sizeY_; i++)
		for (int j = obj.posX_; j < obj.posX_ + obj.sizeX_; j++)
			field_[i][j] = ' ';
}
void GameField::drawObject(const GameObject& obj) {
	for (int i = obj.posY_; i < obj.posY_ + obj.sizeY_; i++)
		for (int j = obj.posX_; j < obj.posX_ + obj.sizeX_; j++)
			field_[i][j] = obj.body_[i - obj.posY_][j - obj.posX_];
}
