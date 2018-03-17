#include "Tank.h"

Tank::Tank(int posX, int posY, int helth) 
	: GameObject(posX, posY, 5, 3)
{
	srand(time(NULL));
	vector[0] = rand() % 2;
	vector[1] = 1 - vector[0];
	helth_ = helth;
}
Tank::Tank(const Tank& tank) : 
	GameObject(tank) {
	helth_ = tank.helth_;
}
Tank& Tank::operator=(const Tank& tank) {
	if (this == &tank)
		return *this;

	GameObject::operator=(tank);
	helth_ = tank.helth_;
	return *this;
}
Tank::~Tank()
{
}
void Tank::move() {
	posX_ += vector[0];
	posY_ += vector[1];
}
void Tank::rotate() {
	vector[0] = -vector[0];
	vector[1] = -vector[1];
}
bool Tank::isDead() const {
	return (helth_ == 0);
}
Shell Tank::shoot() const {
	return Shell(posX_ + 2, posY_ + 1, vector[0], vector[1]);
}
bool Tank::isWounded(const Shell& shell) {
	bool checkY = (shell.posY_ >= posY_ && shell.posY_ <= posY_ + sizeY_ - 1);
	bool checkX = (shell.posX_ >= posX_ && shell.posX_ <= posX_ + sizeX_ - 1);
	if (checkX == true) {
		if (shell.vector[1] == 0)
			return false;
		int distance = shell.posY_ - posY_;
		if (distance > 0 && distance < -shell.vector[1]) {
			helth_--;
			return true;
		}
		if (distance < 0 && distance < -shell.vector[1]) {
			helth_--;
			return true;
		}
	}
	if (checkY == true) {
		if (shell.vector[0] == 0)
			return false;
		int distance = shell.posX_ - posX_;
		if (distance > 0 && distance < -shell.vector[0]) {
			helth_--;
			return true;
		}
		if (distance < 0 && distance > -shell.vector[0]) {
			helth_--;
			return true;
		}
	}
	return false;
}