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
	
	EnemyTank tank(3, 5);
	EnemyTank tank1(10, 5);
	EnemyTank tank2(20, 1);
	Shell shell(0, 0, 0, 0);
	PlayersTank player(45,25);
	Wall wall(3, 4, 10, Wall::GORIZONTAL);
	shell = tank1.shoot();
	while (true) {
		field.drawObject(wall);
		field.drawObject(tank1);
		field.drawObject(tank2);
		field.drawObject(shell);
		field.drawObject(player);
		field.print();
		std::this_thread::sleep_for(std::chrono::microseconds(100000));
		field.deleteObject(player);
		player.control();
		field.deleteObject(shell);
		//field.deleteObject(wall);
		field.deleteObject(tank1);
		field.deleteObject(tank2);
		
		tank.move();
		tank1.move();
		tank2.move();
		shell.move();
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

