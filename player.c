#include "player.h"

// Déplace le joueur d'une case (dx, dy), en poussant la caisse devant lui si la case suivante est libre
static void step(struct Grid *g, int dx, int dy)
{
    enum CaseType *here = &g->game_grid[g->p->x][g->p->y];
    enum CaseType *next = &g->game_grid[g->p->x + dx][g->p->y + dy];
    if (*next == BOX || *next == BOX_INTO_GOAL)
    {
        enum CaseType *after = &g->game_grid[g->p->x + 2 * dx][g->p->y + 2 * dy];
        if (*after != NONE && *after != GOAL)
            return;
        g->game_goal_covered += (*after == GOAL) - (*next == BOX_INTO_GOAL);
        *after = (*after == GOAL) ? BOX_INTO_GOAL : BOX;
        *next = (*next == BOX_INTO_GOAL) ? GOAL : NONE;
    }
    if (*next != NONE && *next != GOAL)
        return;
    *next = (*next == GOAL) ? PLAYER_INTO_GOAL : PLAYER;
    *here = (*here == PLAYER_INTO_GOAL) ? GOAL : NONE;
    g->p->x += dx;
    g->p->y += dy;
}

void move_player(struct Grid *g, enum Event d)
{
    switch (d)
    {
    case LEFT:
        step(g, 0, -1);
        break;
    case RIGHT:
        step(g, 0, 1);
        break;
    case UP:
        step(g, -1, 0);
        break;
    case DOWN:
        step(g, 1, 0);
        break;
    case NOTHING:
        break;
    case QUIT:
        run = false;
        break;
    }
}
