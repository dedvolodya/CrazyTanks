#pragma once
#include "Tank.h"
#include<conio.h>

class PlayersTank :
	public Tank
{
public:
	void rotate() = delete;
	void control();
	PlayersTank(int posX, int posY);
	~PlayersTank();
};
