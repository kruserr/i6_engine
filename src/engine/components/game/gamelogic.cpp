#include "gamelogic.h"
#include "gameobjects/player.h"
#include "gameobjects/wall.h"
#include "gameobjects/background.h"

GameLogic::GameLogic(SDL_Renderer* aRenderer)
{
    renderer = aRenderer;
    player = new Player();	// Construct player
    background = new Background();	// Construct background
}

GameLogic::~GameLogic()
{
    delete player;	// Deconstruct player
    delete background;	// Deconstruct background
}

// All initilization code for the game shall be placed in the init
void GameLogic::initilize()
{
    // ############################## Render Background ##############################
    background->setRenderer(*renderer);
    background->init();
    // ############################## Render Background ##############################

    // ############################## Render Walls ##############################
    init_wall(number_of_walls);
    set_wall(0, (screen_width - wall[0].get_texture_width()) / 2, 0);
    set_wall(1, ((screen_width - wall[1].get_texture_width()) / 2) - 200, screen_height - wall[1].get_texture_height());
    set_wall(2, ((screen_width - wall[2].get_texture_width()) / 2) + 200, screen_height - wall[2].get_texture_height());
    set_wall(3, ((screen_width - wall[3].get_texture_width()) / 2) + 400, 0);
    // ############################## Render Walls ##############################

    // ############################## Render Player ##############################
    player->setRenderer(*renderer);
    player->init();

    // ############################## Render Player ##############################

}

// All initilization code for the game shall be placed in the init
void GameLogic::loop(SDL_Event* aEvent)
{

    // ############################## Tick Background ##############################
    background->refresh();
    // ############################## Tick Background ##############################

    // ############################## Tick Walls ##############################
    for (int i = 0; i < number_of_walls; i++)
    {
        wall[i].refresh();
    }
    // ############################## Tick Walls ##############################

    // ############################## Tick Player ##############################
    player->refresh();
    player->keyboard_input(*aEvent);
    player->movement(get_sync());
    // ############################## Tick Player ##############################
    
    //set_bounds();
    //set_collision();

    // SET CAMERA TO FOLLOW PLAYER
    if (camera_pos_x < (player->get_x() - screen_x_origon + screen_width - screen_width / 2))
        camera_pos_x += (player->get_x() - screen_x_origon - camera_pos_x - screen_width / 2) / camera_speed;
    if (camera_pos_x > (player->get_x() - screen_x_origon + screen_width - screen_width / 2))
        camera_pos_x -= (camera_pos_x - player->get_x() + screen_x_origon - screen_width / 2) / camera_speed;

    if (camera_pos_y < (player->get_y() - screen_y_origon + screen_height - screen_height/ 2 ))
        camera_pos_y += (player->get_y() - screen_y_origon - camera_pos_y - screen_height / 2 ) / camera_speed;
    if (camera_pos_y > (player->get_y() - screen_y_origon + screen_height - screen_height / 2 ))
        camera_pos_y -= (camera_pos_y - player->get_y() + screen_y_origon - screen_height / 2 ) / camera_speed;
    

    // SET NEW ORIGON OF THE GLOBAL CORDINATE SYSTEM
    screen_x_origon = 0 - camera_pos_x;
    screen_y_origon = 0 - camera_pos_y;

    // CAMERA CALCULATIONS
    delta_camera_pos_x = camera_pos_x - camera_pos_x_old;
    delta_camera_pos_y = camera_pos_y - camera_pos_y_old;
    camera_pos_x_old = camera_pos_x;
    camera_pos_y_old = camera_pos_y;
}

// Set Game world bounds
void GameLogic::set_bounds()
{
    
    // ############################## X Bounds ##############################
    if (player->get_x() < screen_x_origon)
        player->set_x(screen_x_origon);
    if (player->get_x() > screen_x_origon + screen_width - player->get_texture_width())
        player->set_x(screen_x_origon);
    // ############################## X Bounds ##############################

    // ############################## Y Bounds ##############################
    if (player->get_y() < screen_y_origon)
        player->set_y(screen_y_origon);
    if (player->get_y() > screen_y_origon + screen_height - player->get_texture_height())
        player->set_y(screen_y_origon + screen_height - player->get_texture_height());
    // ############################## Y Bounds ##############################
    
}

// Set Game Object Collision
void GameLogic::set_collision()
{
    for (int i = 0; i < wall.size(); i++)
    {
        if (player->collides_with(&wall[i]))
        {
                player->set_x(player->get_x_previous() - delta_camera_pos_x);
                player->set_y(player->get_y_previous() - delta_camera_pos_y);
        }
    }
}

void GameLogic::init_wall(int aSize)
{
    wall.resize(aSize);

    for (size_t i = 0; i < wall.size(); i++)
    {
        wall[i].setRenderer(*renderer);
        wall[i].init();
    }
}

void GameLogic::set_wall(int aIndex, double aPos_x, double aPos_y)
{
    wall[aIndex].set_x(aPos_x);
    wall[aIndex].set_y(aPos_y);
}

void GameLogic::generate_wall()
{
    // test2
}
