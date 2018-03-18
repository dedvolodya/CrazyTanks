#include "Game.h"


Game::Game() : player(45,24) , field(90,28)
{
	points = 0;
	time = 0;
	generateWalls();
	generateTanks();
	drawWalls();
	
}
Game::~Game()
{
}
void Game::gameLoop() {
	while (enemyTanks.size() != 0) {
		field.drawObject(player);
		drawShells();
		field.print();
		printGameStatus();
		time++;
		std::this_thread::sleep_for(std::chrono::microseconds(100000));
		processHits();
		processTanks();
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
	}
	system("cls");
	std::cout << "YOU WON" << std::endl;
	std::cout << "POINTS : " << std::to_string(points);
}
void Game::processHits() {
	auto i = enemyTanks.begin();
	while ( i != enemyTanks.end() )
		if (i->isWounded(playerShell) == true) {
			points++;
			field.deleteObject(*i);
			i = enemyTanks.erase(i);		
			field.deleteObject(playerShell);
			playerShell = Shell(0, 0, 0, 0);
			break;
		}
		else {
			i++;
		}
	field.deleteObject(player);
	if (field.isBarrier(playerShell) == true) {
		field.deleteObject(playerShell);
		playerShell = Shell(0, 0, 0, 0);
	}
	field.drawObject(player);
	field.deleteObject(playerShell);
	playerShell.move();
	field.drawObject(playerShell);	

	deleteTanks();
	auto j = enemyShells.begin();
	while (j != enemyShells.end()) {
		field.deleteObject(*j);
		if (field.isBarrier(*j) == true)
			j = enemyShells.erase(j);
		else {
			j->move();
			field.drawObject(*j);
			j++;
		}
	}
	drawTanks();
}
void Game::processTanks() {
	for (auto i = enemyTanks.begin(); i != enemyTanks.end(); i++) {
		if (field.isBarrier(*i) == true) {
			i->rotate();
		}		
		else {
			field.deleteObject(*i);
			i->move();
			field.drawObject(*i);
		}
		if (time % 10 == 0) {
			enemyShells.push_back(i->shoot());
			enemyShells.back().move();
		}
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
void Game::generateTanks() {
	enemyTanks.push_back(EnemyTank(2,2,1,0));
	enemyTanks.push_back(EnemyTank(2, 9, 0, 1));
	enemyTanks.push_back(EnemyTank(84, 1, 0, 1));
	enemyTanks.push_back(EnemyTank(45, 1, 1, 0));
	enemyTanks.push_back(EnemyTank(84, 17, -1, 0));
}
void Game::generateWalls() {
	walls.push_back(Wall(0, 7, 20, Wall::GORIZONTAL));
	walls.push_back(Wall(44, 0, 7, Wall::VERTICAL));
	walls.push_back(Wall(12, 21, 12, Wall::GORIZONTAL));
	walls.push_back(Wall(75, 20, 15, Wall::GORIZONTAL));
	walls.push_back(Wall(50, 15, 18, Wall::GORIZONTAL));
	walls.push_back(Wall(70, 4, 7, Wall::VERTICAL));
}
void Game::printGameStatus() {
	std::string status = "LIVE : ";
	status += std::to_string(player.getHelth());
	status += "\tPOINTS : ";
	status += std::to_string(points);
	std::cout << status;
}