#pragma once
#include "Tank.h"
class EnemyTank : public Tank
{
public:
	EnemyTank(int posX, int posY, int directionX, int directionY);
	EnemyTank(const EnemyTank& tank);
	EnemyTank& operator=(const EnemyTank& tank);
	~EnemyTank();
};

