#include"GameField.h"
#include"EnemyTank.h"
#include"Shell.h"
#include"PlayersTank.h"
#include"Wall.h"

#include<chrono>
#include<thread>
#include<conio.h>


using namespace std;

int main()
{
	GameField field(90, 28);
	
	EnemyTank tank(25, 15);
	EnemyTank tank1(10, 5);
	EnemyTank tank2(20, 1);
	Shell shell(20, 26, 1, 0);
	PlayersTank player(45,25);
	Wall wall(22, 7, 10, Wall::GORIZONTAL);
	//shell = tank1.shoot();
	while (true) {
		field.drawObject(wall);
		field.drawObject(tank);
		field.drawObject(player);
		field.drawObject(shell);
		field.print();
		std::this_thread::sleep_for(std::chrono::microseconds(10000));
		if (field.isBarrier(tank) == true)
			tank.rotate();
		field.deleteObject(shell);
		if (field.isBarrier(shell) == false)
			shell.move();
		field.deleteObject(player);
		if (player.isWounded(shell) != true)
			player.control();
		field.deleteObject(tank);
		tank.move();
		
		
	}
	getchar();
	//while (true) {
	//	std::cout << "a";
	//	if (_kbhit()) {
	//		if (_getch() == ' ') {
	//			std::cout << "b";
	//		}
	//		std::this_thread::sleep_for(std::chrono::microseconds(1000));
	//	}
	//	std::this_thread::sleep_for(std::chrono::microseconds(100));
	//	//Sleep(500);
	//}
    return 0;
}

