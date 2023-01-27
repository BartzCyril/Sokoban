#include "sdl2.h"
#include "math.h"

void sdl_init()
{
  int const width = 1000;
  int const height = 500;
  context = (SDLContext){NULL, NULL, .width = 0, .height = 0};
  if (SDL_Init(SDL_INIT_VIDEO) != 0)
  {
    SDL_Log("Ereur");
    exit(EXIT_FAILURE);
  }
  SDL_Window *window = NULL;
  window = SDL_CreateWindow("Sokoban", 0, 0, 1000, 500, 0);
  if (window == NULL)
  {
    SDL_Log("Ereur window");
    exit(EXIT_FAILURE);
  }
  SDL_Renderer *renderer = NULL;
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL)
  {
    SDL_Log("Ereur renderer");
    exit(EXIT_FAILURE);
  }
  context = (SDLContext){
      .window = window, .renderer = renderer, .width = width, .height = height};
}

void display_sdl2(struct Grid *g)
{

  float const frac_t_1 = (float)1 / (float)20;
  float const frac_t_2 = (float)19 / (float)20;
  float const rapport_ligne = ((context.height * frac_t_2) - (context.height * frac_t_1)) / (g->row_number);
  float const rapport_colonne = ((float)context.width / (float)(g->column_number));
  float const diagonale = sqrt(pow(rapport_colonne, 2) + pow(rapport_ligne, 2));
  float const diagonale_4 = diagonale / 4;

  SDL_SetRenderDrawColor(context.renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
  SDL_Rect buttons_game;
  buttons_game.x = 0;
  buttons_game.y = 0;
  buttons_game.w = 1000;
  buttons_game.h = 500;
  SDL_RenderFillRect(context.renderer, &buttons_game);

  int k = 0, compteur = 0;
  for (int i = 0; i < g->row_number; i++)
  {
    for (int j = 0; j < g->column_number; j++)
    {
      if (g->game_grid[i][j] == WALL)
      {
        // WALL NOIR
        SDL_SetRenderDrawColor(context.renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_FRect wall;
        wall.x = (k * rapport_colonne);
        wall.y = (context.height * frac_t_1) + (compteur * rapport_ligne);
        wall.h = rapport_ligne;
        wall.w = rapport_colonne;
        SDL_RenderFillRectF(context.renderer, &wall);
        k++;
      }
      else if (g->game_grid[i][j] == PLAYER)
      {
        // PLAYER BLANC
        SDL_SetRenderDrawColor(context.renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_FRect player;
        player.x = (k * rapport_colonne) + diagonale_4;
        player.y = ((context.height * frac_t_1) + (compteur * rapport_ligne)) + (rapport_ligne / 4);
        player.h = (rapport_ligne / 2);
        player.w = diagonale_4;
        SDL_RenderFillRectF(context.renderer, &player);
        k++;
      }
      else if (g->game_grid[i][j] == BOX)
      {
        // BOX BRUN
        SDL_SetRenderDrawColor(context.renderer, 91, 60, 17, SDL_ALPHA_OPAQUE);
        SDL_FRect box;
        box.x = (k * rapport_colonne);
        box.y = (context.height * frac_t_1) + (compteur * rapport_ligne);
        box.h = rapport_ligne;
        box.w = rapport_colonne;
        SDL_RenderFillRectF(context.renderer, &box);
        k++;
      }
      else if (g->game_grid[i][j] == GOAL)
      {
        // GOAL POINT EN OR
        SDL_SetRenderDrawColor(context.renderer, 255, 215, 0, SDL_ALPHA_OPAQUE);
        SDL_FRect goal;
        goal.x = (k * rapport_colonne) + diagonale_4;
        goal.y = ((context.height * frac_t_1) + (compteur * rapport_ligne)) + (rapport_ligne / 4);
        goal.h = (rapport_ligne / 2);
        goal.w = diagonale_4;
        SDL_RenderFillRectF(context.renderer, &goal);
        k++;
      }
      else if (g->game_grid[i][j] == BOX_INTO_GOAL)
      {
        // BOX_INTO_GOAL OR
        SDL_SetRenderDrawColor(context.renderer, 255, 215, 0, SDL_ALPHA_OPAQUE);
        SDL_FRect box_into_goal;
        box_into_goal.x = (k * rapport_colonne);
        box_into_goal.y = (context.height * frac_t_1) + (compteur * rapport_ligne);
        box_into_goal.h = rapport_ligne;
        box_into_goal.w = rapport_colonne;
        SDL_RenderFillRectF(context.renderer, &box_into_goal);
        k++;
      }
      else if (g->game_grid[i][j] == PLAYER_INTO_GOAL)
      {
        // PLAYER_INTO_GOAL or avec un point blanc
        SDL_SetRenderDrawColor(context.renderer, 255, 215, 0, SDL_ALPHA_OPAQUE);
        SDL_FRect player_into_goal;
        player_into_goal.x = (k * rapport_colonne);
        player_into_goal.y = (context.height * frac_t_1) + (compteur * rapport_ligne);
        player_into_goal.h = rapport_ligne;
        player_into_goal.w = rapport_colonne;
        SDL_RenderFillRectF(context.renderer, &player_into_goal);
        SDL_SetRenderDrawColor(context.renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_FRect player;
        player.x = (k * rapport_colonne) + diagonale_4;
        player.y = ((context.height * frac_t_1) + (compteur * rapport_ligne)) + (rapport_ligne / 4);
        player.h = (rapport_ligne / 2);
        player.w = diagonale_4;
        SDL_RenderFillRectF(context.renderer, &player);
        k++;
      }
      else if (g->game_grid[i][j] == NONE)
      {
        // NONE vert
        SDL_SetRenderDrawColor(context.renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
        SDL_FRect none;
        none.x = (k * rapport_colonne) + diagonale_4;
        none.y = ((context.height * frac_t_1) + (compteur * rapport_ligne)) + (rapport_ligne / 4);
        none.h = rapport_ligne - diagonale_4;
        none.w = diagonale_4;
        SDL_RenderFillRectF(context.renderer, &none);
        k++;
      }
    }
    compteur++;
    k = 0;
  }
  SDL_RenderPresent(context.renderer);
}

enum Event event()
{
  char entry = fgetc(stdin);
  switch (entry)
  {
  case 'q':
  {
    return QUIT;
    break;
  }
  case 'l':
  {
    return RIGHT;
    break;
  }
  case 'h':
  {
    return LEFT;
    break;
  }
  case 'k':
  {
    return UP;
    break;
  }
  case 'j':
  {
    return DOWN;
    break;
  }
  default:
  {
    return NOTHING;
  }
  }
}

enum Event event_sdl2()
{
  SDL_Event event;
  SDL_WaitEvent(&event);
  switch (event.type)
  {
  case SDL_KEYUP:
    switch (event.key.keysym.sym)
    {
    case SDLK_h:
    {
      return LEFT;
      break;
    }
    case SDLK_j:
    {
      return DOWN;
      break;
    }
    case SDLK_k:
    {
      return UP;
      break;
    }
    case SDLK_l:
    {
      return RIGHT;
      break;
    }
    case SDLK_q:
    {
      return QUIT;
      break;
    }
    }
  }
  return NOTHING;
}

enum Event handle_event(enum Event (*pf)())
{
  return (*pf)();
}

void sdl_quit()
{
  SDL_DestroyWindow(context.window);
  SDL_DestroyRenderer(context.renderer);
  context.window = NULL;
  context.renderer = NULL;
  SDL_Quit();
}
