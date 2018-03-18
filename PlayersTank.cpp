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
PlayersTank::PlayersTank(const PlayersTank& tank) : 
	Tank(tank) {

}
PlayersTank& PlayersTank::operator=(const PlayersTank& tank) {
	if (this == &tank)
		return *this;
	Tank::operator=(tank);
	return *this;
}
void PlayersTank::control(int button) {
		switch (button)
		{
		case (75) :  //left
			vector[0] = -1;
			vector[1] = 0;
			break;
		case (77) :  //right
			vector[0] = 1;
			vector[1] = 0;
			break;
		case (72) :   //up
			vector[0] = 0;
			vector[1] = -1;
			break;
		case (80) :   //down
			vector[0] = 0;
			vector[1] = 1;
			break;
		}
}
int PlayersTank::getHelth() {
	return helth_;
}
PlayersTank::~PlayersTank()
{
}
