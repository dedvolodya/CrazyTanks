#include "PlayersTank.h"


PlayersTank::PlayersTank(int posX, int posY)
	: Tank(posX, posY, 3)
{
	for (int i = 0; i < sizeY_; i++)
		for (int j = 0; j < sizeX_; j++)
			body_[i][j] = '@';
	vector[0] = 0;
	vector[1] = 0;
}
void PlayersTank::control() {
	int botton;
	if (_kbhit()) {
		botton = static_cast<int>(getch());
		switch (botton)
		{
		case (75) :  //left
			vector[0] = -1;
			vector[1] = 0;
			posX_--;
			break;
		case (77) :  //right
			vector[0] = 1;
			vector[1] = 0;
			posX_++;
		case (72) :   //up
			vector[0] = 0;
			vector[1] = -1;
			posY_--;
			break;
		case (80) :   //down
			vector[0] = 0;
			vector[1] = 1;
			posY_++;
			break;
		}
	}
}
PlayersTank::~PlayersTank()
{
}
