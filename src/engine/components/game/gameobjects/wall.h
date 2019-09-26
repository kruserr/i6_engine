#ifndef WALL_H
#define WALL_H

#include "..//GameObject.h"

class Wall : public GameObject
{
private:

public:
	Wall();

	//gameobject components
	void gameObjectRun() { refresh(); }
};

#endif // !WALL_H
