#pragma once
#include "GameObject.h"
class Shell :
	public GameObject
{
public:
	Shell(int posX, int posY, int directionX, int directionY);
	~Shell();
	void move();
private:
	int vector[2];
};

