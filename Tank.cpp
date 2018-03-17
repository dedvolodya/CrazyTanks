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