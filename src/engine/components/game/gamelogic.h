#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "..//..//..//pch.h"
#include "gameobjects/player.h"
#include "gameobjects/wall.h"
#include "gameobjects/background.h"

	class GameLogic
    {
	private:
		SDL_Renderer* renderer;
		Player *player;
		Background *background;

        int number_of_walls = 4;
        std::vector<Wall> wall;
        
        Uint32 sync_start = 0;
        Uint32 sync_end = 0;
        double sync = 0;

	public:
		GameLogic() = delete;
		GameLogic(SDL_Renderer *aRenderer);
		~GameLogic();

		void initilize();
		void loop(SDL_Event* aEvent);

        Uint32 get_sync_start() { return sync_start; }
        Uint32 get_sync_end() { return sync_end; }
        double get_sync() { return (get_sync_start() - get_sync_end()) * player->get_player_speed(); }
        void set_sync_start() { sync_start = SDL_GetTicks(); }
        void set_sync_end() { sync_end = sync_start; }

        void set_bounds();
        void set_collision();

        void init_wall(int aSize);
        void set_wall(int aIndex, double aPos_x, double aPos_y);
        void generate_wall();
	};

#endif
