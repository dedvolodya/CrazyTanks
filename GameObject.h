#pragma once
#include <cstdlib>
#include <ctime>
class GameObject
{
	friend class GameField;
protected:
	char** body_;
	int posX_;
	int posY_;
	int sizeX_;
	int sizeY_;
public:
	GameObject(int PosX, int PosY, int sizeX, int sizeY);
	~GameObject();
};

