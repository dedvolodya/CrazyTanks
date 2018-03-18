#pragma once
#include<iostream>
#include"GameObject.h"

class GameField
{
public:
	GameField(int sizeX, int sizeY);
	void drawObject(const GameObject& obj);
	void deleteObject(const GameObject& obj);
	bool isBarrier(const GameObject& obj);
	int getSizeX();
	int getSizeY();
	~GameField();
	void print() const;
private:	
	int sizeX_ ;
	int sizeY_ ;
	char** field_ = NULL;
};

