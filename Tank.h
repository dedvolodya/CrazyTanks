#pragma once
#include "GameObject.h"

class Tank : public GameObject
{
	friend class GameField;
protected:
	int helth_;
	int vector[2];//direct vector
public:
	void shoot();
	bool isDead();
	void move();
	void rotate();
	Tank(int posX, int posY, int helth);
	~Tank();
};
