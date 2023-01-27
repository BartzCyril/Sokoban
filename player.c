#include "player.h"
void move_player(struct Grid *g, enum Event d)
{
    switch (d)
    {
    case LEFT:
    {
        if(g->game_grid[g->p->x][g->p->y] == PLAYER_INTO_GOAL) {
            if (g->game_grid[g->p->x][g->p->y - 1] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x][g->p->y - 1] = PLAYER;
                g->p->y--;
            }
            else if (g->game_grid[g->p->x][g->p->y - 1] == BOX && g->game_grid[g->p->x][g->p->y - 2] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x][g->p->y - 1] = PLAYER;
                g->game_grid[g->p->x][g->p->y - 2] = BOX;
                g->p->y--;
            }
            else if (g->game_grid[g->p->x][g->p->y - 1] == GOAL) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x][g->p->y - 1] = PLAYER_INTO_GOAL;
                g->p->y--;
            }
            else if (g->game_grid[g->p->x][g->p->y - 1] == BOX_INTO_GOAL && g->game_grid[g->p->x][g->p->y - 2] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x][g->p->y - 1] = PLAYER_INTO_GOAL;
                g->game_grid[g->p->x][g->p->y - 2] = BOX;
                g->p->y--;
                g->game_goal_covered--;
            }
        }
        else if (g->game_grid[g->p->x][g->p->y - 1] == BOX_INTO_GOAL) {
            if (g->game_grid[g->p->x][g->p->y - 2] == NONE) {
                g->game_grid[g->p->x][g->p->y] = NONE;
                g->game_grid[g->p->x][g->p->y - 1] = PLAYER_INTO_GOAL; 
                g->game_grid[g->p->x][g->p->y - 2] = BOX; 
                g->p->y--;
                g->game_goal_covered--;
            }
            else if(g->game_grid[g->p->x][g->p->y - 2] == GOAL) {
                g->game_grid[g->p->x][g->p->y] = NONE;
                g->game_grid[g->p->x][g->p->y - 1] = PLAYER_INTO_GOAL; 
                g->game_grid[g->p->x][g->p->y - 2] = BOX_INTO_GOAL; 
                g->p->y--;
            }
        }
        else if (g->game_grid[g->p->x][g->p->y - 1] == GOAL) {
            g->game_grid[g->p->x][g->p->y] = NONE; 
            g->game_grid[g->p->x][g->p->y - 1] = PLAYER_INTO_GOAL;
            g->p->y--;
        }
        else if (g->game_grid[g->p->x][g->p->y - 1] == NONE)
        {
            g->game_grid[g->p->x][g->p->y - 1] = g->game_grid[g->p->x][g->p->y];
            g->game_grid[g->p->x][g->p->y] = NONE;
            g->p->y--;
        }
        else if (g->game_grid[g->p->x][g->p->y - 1] == BOX && g->game_grid[g->p->x][g->p->y - 2] == NONE)
        {
            g->game_grid[g->p->x][g->p->y - 1] = g->game_grid[g->p->x][g->p->y];
            g->game_grid[g->p->x][g->p->y - 2] = BOX;
            g->game_grid[g->p->x][g->p->y] = NONE;
            g->p->y--;
        }
        else if (g->game_grid[g->p->x][g->p->y - 1] == BOX && g->game_grid[g->p->x][g->p->y - 2] == GOAL) {
            g->game_grid[g->p->x][g->p->y] = NONE; 
            g->game_grid[g->p->x][g->p->y - 1] = PLAYER;
            g->game_grid[g->p->x][g->p->y - 2] = BOX_INTO_GOAL; 
            g->p->y--;
            g->game_goal_covered++;
        }
        break;
    }
    case RIGHT:
    {
        if(g->game_grid[g->p->x][g->p->y] == PLAYER_INTO_GOAL) {
            if (g->game_grid[g->p->x][g->p->y + 1] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x][g->p->y + 1] = PLAYER;
                g->p->y++;
            }
            else if (g->game_grid[g->p->x][g->p->y + 1] == BOX && g->game_grid[g->p->x][g->p->y + 2] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x][g->p->y + 1] = PLAYER;
                g->game_grid[g->p->x][g->p->y + 2] = BOX;
                g->p->y++;
            }
            else if (g->game_grid[g->p->x][g->p->y + 1] == GOAL) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x][g->p->y + 1] = PLAYER_INTO_GOAL;
                g->p->y++;
            }
            else if (g->game_grid[g->p->x][g->p->y + 1] == BOX_INTO_GOAL && g->game_grid[g->p->x][g->p->y + 2] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x][g->p->y + 1] = PLAYER_INTO_GOAL;
                g->game_grid[g->p->x][g->p->y + 2] = BOX;
                g->p->y++;
                g->game_goal_covered--;
            }
        }
        else if (g->game_grid[g->p->x][g->p->y + 1] == BOX_INTO_GOAL) {
            if (g->game_grid[g->p->x][g->p->y + 2] == NONE) {
                g->game_grid[g->p->x][g->p->y] = NONE;
                g->game_grid[g->p->x][g->p->y + 1] = PLAYER_INTO_GOAL; 
                g->game_grid[g->p->x][g->p->y + 2] = BOX; 
                g->p->y++;
                g->game_goal_covered--;
            }
            else if(g->game_grid[g->p->x][g->p->y + 2] == GOAL) {
                g->game_grid[g->p->x][g->p->y] = NONE;
                g->game_grid[g->p->x][g->p->y + 1] = PLAYER_INTO_GOAL; 
                g->game_grid[g->p->x][g->p->y + 2] = BOX_INTO_GOAL; 
                g->p->y++;
            }
        }
        else if (g->game_grid[g->p->x][g->p->y + 1] == GOAL) {
            g->game_grid[g->p->x][g->p->y] = NONE; 
            g->game_grid[g->p->x][g->p->y + 1] = PLAYER_INTO_GOAL;
            g->p->y++;
        }
        else if (g->game_grid[g->p->x][g->p->y + 1] == NONE)
        {
            g->game_grid[g->p->x][g->p->y + 1] = g->game_grid[g->p->x][g->p->y];
            g->game_grid[g->p->x][g->p->y] = NONE;
            g->p->y++;
        }
        else if (g->game_grid[g->p->x][g->p->y + 1] == BOX && g->game_grid[g->p->x][g->p->y + 2] == NONE)
        {
            g->game_grid[g->p->x][g->p->y + 1] = g->game_grid[g->p->x][g->p->y];
            g->game_grid[g->p->x][g->p->y + 2] = BOX;
            g->game_grid[g->p->x][g->p->y] = NONE;
            g->p->y++;
        }
        else if (g->game_grid[g->p->x][g->p->y + 1] == BOX && g->game_grid[g->p->x][g->p->y + 2] == GOAL) {
            g->game_grid[g->p->x][g->p->y] = NONE; 
            g->game_grid[g->p->x][g->p->y + 1] = PLAYER;
            g->game_grid[g->p->x][g->p->y + 2] = BOX_INTO_GOAL; 
            g->p->y++;
            g->game_goal_covered++;
        }
        break;
    }
    case UP:
    {
        if(g->game_grid[g->p->x][g->p->y] == PLAYER_INTO_GOAL) {
            if (g->game_grid[g->p->x - 1][g->p->y] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x - 1][g->p->y] = PLAYER;
                g->p->x--;
            }
            else if (g->game_grid[g->p->x - 1][g->p->y] == BOX && g->game_grid[g->p->x - 2][g->p->y] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x - 1][g->p->y] = PLAYER;
                g->game_grid[g->p->x - 2][g->p->y] = BOX;
                g->p->x--;
            }
            else if (g->game_grid[g->p->x - 1][g->p->y] == GOAL) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x - 1][g->p->y] = PLAYER_INTO_GOAL;
                g->p->x--;
            }
            else if (g->game_grid[g->p->x - 1][g->p->y] == BOX_INTO_GOAL && g->game_grid[g->p->x - 2][g->p->y] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x - 1][g->p->y] = PLAYER_INTO_GOAL;
                g->game_grid[g->p->x - 2][g->p->y] = BOX;
                g->p->x--;
                g->game_goal_covered--;
            }
        }
        else if (g->game_grid[g->p->x - 1][g->p->y] == BOX_INTO_GOAL) {
            if (g->game_grid[g->p->x - 2][g->p->y] == NONE) {
                g->game_grid[g->p->x][g->p->y] = NONE;
                g->game_grid[g->p->x - 1][g->p->y] = PLAYER_INTO_GOAL; 
                g->game_grid[g->p->x - 2][g->p->y] = BOX; 
                g->p->x--;
                g->game_goal_covered--;
            }
            else if(g->game_grid[g->p->x - 2][g->p->y] == GOAL) {
                g->game_grid[g->p->x][g->p->y] = NONE;
                g->game_grid[g->p->x - 1][g->p->y] = PLAYER_INTO_GOAL; 
                g->game_grid[g->p->x - 2][g->p->y] = BOX_INTO_GOAL; 
                g->p->x--;
            }
        }
        else if (g->game_grid[g->p->x - 1][g->p->y] == GOAL) {
            g->game_grid[g->p->x][g->p->y] = NONE; 
            g->game_grid[g->p->x - 1][g->p->y] = PLAYER_INTO_GOAL;
            g->p->x--;
        }
        else if (g->game_grid[g->p->x - 1][g->p->y] == NONE)
        {
            g->game_grid[g->p->x - 1][g->p->y] = g->game_grid[g->p->x][g->p->y];
            g->game_grid[g->p->x][g->p->y] = NONE;
            g->p->x--;
        }
        else if (g->game_grid[g->p->x - 1][g->p->y] == BOX && g->game_grid[g->p->x - 2][g->p->y] == NONE)
        {
            g->game_grid[g->p->x - 1][g->p->y] = g->game_grid[g->p->x][g->p->y];
            g->game_grid[g->p->x - 2][g->p->y] = BOX;
            g->game_grid[g->p->x][g->p->y] = NONE;
            g->p->x--;
        }
        else if (g->game_grid[g->p->x - 1][g->p->y] == BOX && g->game_grid[g->p->x - 2][g->p->y] == GOAL) {
            g->game_grid[g->p->x][g->p->y] = NONE; 
            g->game_grid[g->p->x - 1][g->p->y] = PLAYER;
            g->game_grid[g->p->x - 2][g->p->y] = BOX_INTO_GOAL; 
            g->p->x--;
            g->game_goal_covered++;
        }
        break;
    }
    case DOWN:
    {
        if(g->game_grid[g->p->x][g->p->y] == PLAYER_INTO_GOAL) {
            if (g->game_grid[g->p->x + 1][g->p->y] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x + 1][g->p->y] = PLAYER;
                g->p->x++;
            }
            else if (g->game_grid[g->p->x + 1][g->p->y] == BOX && g->game_grid[g->p->x + 2][g->p->y] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x + 1][g->p->y] = PLAYER;
                g->game_grid[g->p->x + 2][g->p->y] = BOX;
                g->p->x++;
            }
            else if (g->game_grid[g->p->x + 1][g->p->y] == GOAL) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x + 1][g->p->y] = PLAYER_INTO_GOAL;
                g->p->x++;
            }
            else if (g->game_grid[g->p->x + 1][g->p->y] == BOX_INTO_GOAL && g->game_grid[g->p->x + 2][g->p->y] == NONE) {
                g->game_grid[g->p->x][g->p->y] = GOAL; 
                g->game_grid[g->p->x + 1][g->p->y] = PLAYER_INTO_GOAL;
                g->game_grid[g->p->x + 2][g->p->y] = BOX;
                g->p->x++;
                g->game_goal_covered--;
            }
        }
        else if (g->game_grid[g->p->x + 1][g->p->y] == BOX_INTO_GOAL) {
            if (g->game_grid[g->p->x + 2][g->p->y] == NONE) {
                g->game_grid[g->p->x][g->p->y] = NONE;
                g->game_grid[g->p->x + 1][g->p->y] = PLAYER_INTO_GOAL; 
                g->game_grid[g->p->x + 2][g->p->y] = BOX; 
                g->p->x++;
                g->game_goal_covered--;
            }
            else if(g->game_grid[g->p->x + 2][g->p->y] == GOAL) {
                g->game_grid[g->p->x][g->p->y] = NONE;
                g->game_grid[g->p->x + 1][g->p->y] = PLAYER_INTO_GOAL; 
                g->game_grid[g->p->x + 2][g->p->y] = BOX_INTO_GOAL; 
                g->p->x++;
            }
        }
        else if (g->game_grid[g->p->x + 1][g->p->y] == GOAL) {
            g->game_grid[g->p->x][g->p->y] = NONE; 
            g->game_grid[g->p->x + 1][g->p->y] = PLAYER_INTO_GOAL;
            g->p->x++;
        }
        else if (g->game_grid[g->p->x + 1][g->p->y] == NONE)
        {
            g->game_grid[g->p->x + 1][g->p->y] = g->game_grid[g->p->x][g->p->y];
            g->game_grid[g->p->x][g->p->y] = NONE;
            g->p->x++;
        }
        else if (g->game_grid[g->p->x + 1][g->p->y] == BOX && g->game_grid[g->p->x + 2][g->p->y] == NONE)
        {
            g->game_grid[g->p->x + 1][g->p->y] = g->game_grid[g->p->x][g->p->y];
            g->game_grid[g->p->x + 2][g->p->y] = BOX;
            g->game_grid[g->p->x][g->p->y] = NONE;
            g->p->x++;
        }
        else if (g->game_grid[g->p->x + 1][g->p->y] == BOX && g->game_grid[g->p->x + 2][g->p->y] == GOAL) {
            g->game_grid[g->p->x][g->p->y] = NONE; 
            g->game_grid[g->p->x + 1][g->p->y] = PLAYER;
            g->game_grid[g->p->x + 2][g->p->y] = BOX_INTO_GOAL; 
            g->p->x++;
            g->game_goal_covered++;
        }
        break;
    }
    case NOTHING : 
    {
        break;
    }
    case QUIT : 
    {
        run = false;
        break;
    }
    }
}
