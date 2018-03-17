#include "EnemyTank.h"
#include<iostream>

EnemyTank::EnemyTank(int posX, int posY) 
	: Tank(posX, posY, 1)
{
	for (int i = 0; i < sizeY_; i++)
		for (int j = 0; j < sizeX_; j++)
			body_[i][j] = '#';
}

void EnemyTank::draw() {
	for (int i = 0; i < sizeY_; i++) {
		for (int j = 0; j < sizeX_; j++)
			std::cout << body_[i][j];
		std::cout << std::endl;
	}
}
EnemyTank::~EnemyTank()
{
}
