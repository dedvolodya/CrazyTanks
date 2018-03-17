#pragma once
#include "GameObject.h"
class Shell :
	public GameObject
{
	friend class GameField;
	friend class Tank;
public:
	Shell(int posX, int posY, int directionX, int directionY);
	Shell(const Shell& shell);
	Shell& operator=(const Shell& shell);
	~Shell();
	void move();
};

