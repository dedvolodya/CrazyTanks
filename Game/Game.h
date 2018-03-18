#pragma once
#include<list>
#include<chrono>
#include<thread>
#include<conio.h>
#include<string>
#include"GameField.h"
#include"EnemyTank.h"
#include"PlayersTank.h"
#include"Wall.h"
#include"Shell.h"

class Game
{
public:
	void generateObject();
	void gameLoop();
	Game();
	~Game();
private:
	void generateWalls();
	void generateTanks();
	void processTanks();
	void processHits();
	void printGameStatus();
	void drawWalls();
	void drawTanks();
	void drawShells();
	void deleteTanks();
	void deleteShells();
	std::list<Wall> walls;
	std::list<EnemyTank> enemyTanks;
	std::list<Shell> enemyShells;
	Shell playerShell;
	PlayersTank player;
	GameField field;
	int points;
};
