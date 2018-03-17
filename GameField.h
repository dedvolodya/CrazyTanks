#pragma once
#include<iostream>
#include"GameObject.h"
#include"Tank.h"

class GameField
{
public:
	GameField(int sizeX, int sizeY);
	void drawObject(const GameObject& obj);
	void deleteObject(const GameObject& obj);
	bool isBarrier(const Tank& tank);
	~GameField();
	void print() const;
private:	
	int sizeX_ ;
	int sizeY_ ;
	char** field_ = NULL;
};

