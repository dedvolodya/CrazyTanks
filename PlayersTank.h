#pragma once
#include "Tank.h"
#include<conio.h>

class PlayersTank :
	public Tank
{
public:
	void rotate() = delete;
	int getHelth();
	void control(int bottonn);
	PlayersTank(int posX, int posY);
	PlayersTank(const PlayersTank& tank);
	PlayersTank& operator=(const PlayersTank& tank);
	~PlayersTank();
};

