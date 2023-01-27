#include <stdio.h>
#include "grid.h"
#include "player.h"
#include "sdl2.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool run;

int main(int argc, char **argv)
{
	char graphic[30] = "";
	char file_grid[6] = "level";
	bool sdl2_graphic = false;
	if (argc == 3)
	{
		if (strcmp(argv[1], "--sdl2") == 0)
		{
			strcat(graphic, argv[1]);
			strcat(file_grid, argv[2]);
			strcat(file_grid, ".txt");
			sdl2_graphic = true;
			sdl_init();
			handle_display = &display_sdl2;
		}
		else
		{
			perror("Erreur si vous voulez lancer en mode graphique : ./sokoban --sdl2 <numéro du niveau>");
			exit(EXIT_FAILURE);
		}
	}
	else if (argc == 1)
	{
		perror("Erreur si vous voulez lancer en mode graphique : ./sokoban --sdl2 <numéro du niveau> ou si vous voulez lancer en mode console : ./sokoban <numéro de niveau>");
		exit(EXIT_FAILURE);
	}
	else
	{
		strcat(file_grid, argv[1]);
		strcat(file_grid, ".txt");
		handle_display = &display;
	}
	struct Grid *g = (struct Grid *)malloc(sizeof(struct Grid));
	if (g == NULL)
	{
		perror("Erreur d'allocation mémoire");
		exit(EXIT_FAILURE);
	}
	init_level(file_grid, g);
	run = true;
	while (run && (g->game_goal != g->game_goal_covered))
	{
		(*handle_display)(g);
		if (sdl2_graphic)
			move_player(g, handle_event(&event_sdl2));
		else
			move_player(g, handle_event(&event));
	}
	if (g->game_goal == g->game_goal_covered)
		printf("Bravo !!!\n");
	if (sdl2_graphic)
		sdl_quit();
	free_struct_and_player(g);
}
