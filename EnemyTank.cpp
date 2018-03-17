#include "EnemyTank.h"

EnemyTank::EnemyTank(int posX, int posY) 
	: Tank(posX, posY, 1)
{
	for (int i = 0; i < sizeY_; i++)
		for (int j = 0; j < sizeX_; j++)
			body_[i][j] = '#';
}

EnemyTank::~EnemyTank()
{
}
EnemyTank::EnemyTank(const EnemyTank& tank) :
	Tank(tank) {

}
EnemyTank& EnemyTank::operator=(const EnemyTank& tank) {
	if (this == &tank)
		return *this;

	Tank::operator=(tank);
	return *this;
}