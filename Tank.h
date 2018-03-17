#pragma once
#include "GameObject.h"
#include "Shell.h"

class Tank : public GameObject
{
	friend class GameField;
protected:
	int helth_;
	int vector[2];//direction vector
public:
	Shell shoot();
	bool isDead();
	void move();
	void rotate();
	Tank(int posX, int posY, int helth);
	~Tank();
};
