#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "..//GameObject.h"

	class Background : public GameObject
	{
	private:

	public:
		Background();

		//gameobject components
		void gameObjectRun() { refresh(); }
	};

#endif // !BACKGROUND_H
