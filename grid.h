/**
 * @file grid.h
 * @author BARTZ
 * @brief 
 * @version 2.2
 * @date 2022-03-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef GRID_HEADER
#define GRID_HEADER

#include "player.h"

enum CaseType{
	WALL = '#',
	BOX = '$',
	PLAYER = '@',
	GOAL = '.',
	NONE = ' ',
	BOX_INTO_GOAL = '*', 
	PLAYER_INTO_GOAL = '+'
};

/**
 * @struct Grid grid.h 
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
struct Grid{
	enum CaseType** game_grid; ///< tableau de tableau contenant les entités présents dans le jeu
	int column_number; ///< nombre de colonne de game_grid
	int row_number; ///< nombre de ligne de game_grid
	struct Player *p; ///< pointeur vers la structure Player qui contient les coordonnées du joueur
	int game_goal; ///< nombre de cases cibles
	int game_goal_covered; ///< nombre de cases cibles recouvert
};

/**
 * @brief Cette fonction permet de créer la structure Grid avec la position initial du joueur, 
 * contient le nombre de colonnes, lignes et de cases cibles ainsi que la grille du jeu. 
 * @param[in] file_path Nom du fichier qui contient la grille du jeu
 * @param[out] g Structure à initialiser 
 */
void init_level(const char* file_path, struct Grid *g);

/**
 * @brief Cette fonction permet d'afficher l'état actuel du jeu 
 * @param[in] g Grille du jeu
*/ 
void display(struct Grid *g);

/**
 * @brief Cette fonction permet de basculer entre la fonction display et la fonction display_sdl2
 * @param[in] pf Adresse de la fonction display ou display_sdl2
 */
void (*handle_display)(struct Grid *);

/**
 * @brief Cette fonction permet de libérer la mémoire du tableau, la structure player ainsi que la structure grid
 * @param[in] g Pointeur sur la structure Grid  
 */
void free_struct_and_player(struct Grid *g);

#endif

