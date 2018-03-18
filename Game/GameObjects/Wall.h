#pragma once
#include "GameObject.h"
class Wall :
	public GameObject
{
public:
	enum Placing {
		GORIZONTAL , VERTICAL
	};
	Wall(int posX, int posY, int size, Placing placing);
	Wall(const Wall& wall);
	Wall& operator=(const Wall& wall);
	~Wall();
};

