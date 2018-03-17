#include "Game.h"


Game::Game() : player(45,24) , field(90,28)
{
	generateWalls(12);
	drawWalls();
	
}
Game::~Game()
{
}
void Game::gameLoop() {
	while (true) {
		field.drawObject(player);
		field.drawObject(playerShell);
		field.print();

		std::this_thread::sleep_for(std::chrono::microseconds(100000));
		field.deleteObject(player);
		if (_kbhit()) {
			int button = static_cast<int>(_getch());
			if (button == 32) {
				field.deleteObject(playerShell);
				playerShell = player.shoot();
			}
			else {
				player.control(button);
				if (field.isBarrier(player) == false)
					player.move();
			}	
		}
		field.deleteObject(playerShell);
		if (field.isBarrier(playerShell) == false)
			playerShell.move();
		else
			playerShell = Shell(0, 0, 0, 0);
					
	}
}
void Game::drawWalls() {
	for (auto i = walls.begin(); i != walls.end(); i++)
		field.drawObject(*i);
}
void Game::drawTanks() {
	for (auto i = enemyTanks.begin(); i != enemyTanks.end(); i++)
		field.drawObject(*i);
	field.drawObject(player);
}
void Game::drawShells() {
	for (auto i = enemyShells.begin(); i != enemyShells.end(); i++)
		field.drawObject(*i);
	field.drawObject(playerShell);
}
void Game::deleteTanks() {
	for (auto i = enemyTanks.begin(); i != enemyTanks.end(); i++)
		field.deleteObject(*i);
	field.deleteObject(player);
}
void Game::deleteShells() {
	for (auto i = enemyShells.begin(); i != enemyShells.end(); i++)
		field.deleteObject(*i);
	field.deleteObject(playerShell);
}
void Game::generateWalls(int n) {
	walls.push_back(Wall(0, 7, 20, Wall::GORIZONTAL));
	walls.push_back(Wall(44, 0, 7, Wall::VERTICAL));
	walls.push_back(Wall(12, 21, 12, Wall::GORIZONTAL));
	walls.push_back(Wall(75, 20, 15, Wall::GORIZONTAL));
	walls.push_back(Wall(50, 15, 18, Wall::GORIZONTAL));
	walls.push_back(Wall(70, 4, 7, Wall::VERTICAL));
}