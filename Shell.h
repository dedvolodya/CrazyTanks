#pragma once
#include "GameObject.h"
class Shell :
	public GameObject
{
public:
	Shell(int posX, int posY, int directionX, int directionY);
	Shell(const Shell& shell);
	Shell& operator=(const Shell& shell);
	~Shell();
	void move();
	bool isBroke();
private:
	int vector[2];
};

