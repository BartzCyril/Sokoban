/**
 * @file player.h
 * @author BARTZ
 * @brief 
 * @version 2.6
 * @date 2022-03-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PLAYER_HEADER
#define PLAYER_HEADER

#include "grid.h"
#include "sdl2.h"
#include <stdbool.h>


struct Grid;
enum Event;
extern bool run; ///< variable extern run pour quitter le programme;

struct Player
{
    int x; ///< Position du joueur en x
    int y; ///< Position du joueur en y
};

/**
 * @brief Cette fonction permet de changer la direction du joueur avec toutes les règles du jeu
 * @param[in] d un event (haut, bas, gauche, droite, rien, quitter) 
 * @param[out] g Pointeur sur la structure Grid
*/
void move_player(struct Grid *g, enum Event d);

#endif