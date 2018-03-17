#include "Tank.h"

Tank::Tank(int posX, int posY, int helth) : GameObject(posX, posY, 5, 3)
{
	srand(time(NULL));
	vector[0] = rand() % 2;
	vector[1] = 1 - vector[0];
	helth_ = helth;
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
bool Tank::isDead() {
	return (helth_ == 0);
}