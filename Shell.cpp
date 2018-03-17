#include "Shell.h"


Shell::Shell(int posX, int posY, int directionX, int directionY) 
	: GameObject(posX, posY, 1, 1)
{
	body_[0][0] = '*';
	vector[0] = 5 * directionX;
	vector[1] = 2 * directionY; 
}
Shell::Shell(const Shell& shell) : GameObject(shell) {
	vector[0] = shell.vector[0];
	vector[1] = shell.vector[1];
}
Shell& Shell::operator=(const Shell& shell) {
	if (this == &shell)
		return *this;
	GameObject::operator=(shell);
	vector[0] = shell.vector[0];
	vector[1] = shell.vector[1];
	return *this;
}
Shell::~Shell()
{
}
void Shell::move() {
	posX_ += vector[0];
	posY_ += vector[1];
}