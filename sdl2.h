/**
 * @file sdl2.h
 * @author BARTZ
 * @brief 
 * @version 2.9
 * @date 2022-03-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <SDL2/SDL.h>
#include "grid.h"

struct Grid;

enum Event {
  QUIT, 
  UP,
  DOWN, 
  LEFT,
  RIGHT,
  NOTHING
};

/**
 * @struct SDLContext sdl2.h
 * @brief 
 * 
 */
typedef struct SDLContext {
  SDL_Window *window; ///< fenêtre
  SDL_Renderer *renderer; ///< rendu de la fenêtre
  int width; ///< largeur de la fenêtre
  int height; ///< hauteur de la fenêtre
} SDLContext;

SDLContext context;

/**
 * @brief Cette fonction permet de créer la fenêtre avec son rendu et d'affecter 
 * le nombre de pixels pour la largeur et la hauteur de la fenêtre
 * @param[out] context Structure contenant toutes les informations pour construire le rendu de la fenêtre
 */
void sdl_init();

/**
 * @brief Cette fonction permet d'afficher l'état actuel du jeu en mode graphique
 * @param[in] g Grille du jeu
*/ 
void display_sdl2(struct Grid *g);

/**
 * @brief Cette fonction permet de renvoyer une action qui doit être produite pendant le jeu en mode console
 * @param[out] enum Event
 */
enum Event event();

/**
 * @brief Cette fonction permet de renvoyer une action qui doit être produite pendant le jeu en mode graphique
 * @param[out] enum Event
 */
enum Event event_sdl2();

/**
 * @brief Cette fonction permet de basculer entre la fonction event et la fonction event_sdl2
 * @param[in] pf Adresse de la fonction event ou event_sdl2
 * @param[out] enum Event
 */
enum Event handle_event(enum Event(*pf)());

/**
 * @brief Cette fonction nettoie la variable global context 
 */
void sdl_quit();
