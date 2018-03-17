#pragma once
#include "Tank.h"
class EnemyTank : public Tank
{
public:
	EnemyTank(int posX, int posY);
	void draw();
	~EnemyTank();
};

