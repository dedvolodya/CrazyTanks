#pragma once
#include "GameObject.h"
#include "Shell.h"

class Tank : public GameObject
{
	friend class GameField;
public:
	Shell shoot() const;
	bool isDead() const;
	void move();
	void rotate();
	Tank(int posX, int posY, int helth);
	Tank(const Tank& tank);
	Tank& operator=(const Tank& tank);
	bool isWounded(const Shell& shell);
	void substractHelth();
	~Tank();
protected:
	int helth_;
};
