#include "grid.h"
#include <stdlib.h>
#include <stdio.h>

void init_level(const char *file_path, struct Grid *g)
{
	// ouverture du fichier en mode lecture
	FILE *file = fopen(file_path, "r");
	if (!file)
	{
		fprintf(stderr, "Error %s not found", file_path);
		exit(-1);
	}
	char line[100] = {0};
	int number_column = 0; // nombre de colonne
	int number_row = 0;	   // nombre de ligne
	int number_goals = 0;
	// on lit la première ligne du fichier
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
	g->row_number = number_row;
	g->column_number = number_column;
	g->game_goal = number_goals;
	g->game_goal_covered = 0;
	// Alloue mémoire pour game_grid
	g->game_grid = (enum CaseType **)malloc(number_row * sizeof(enum CaseType *));
	for (int i = 0; i < number_row; i++)
	{
		g->game_grid[i] = (enum CaseType *)malloc(number_column * sizeof(enum CaseType));
	}
	// Gestion erreur allocation 
	if (g->game_grid == NULL) {
		perror("Erreur");
		exit(EXIT_FAILURE);
	}
	int current_row = 0;
	// int current_goal = 0;
	//  On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while (fgets(line, 100, file) != NULL)
	{
		int current_column = 0;
		char *buffer = line;
		while (*buffer && *buffer != '\n')
		{
			switch (line[current_column])
			{
			case '#':
				g->game_grid[current_row][current_column] = WALL;
				break;
			case '.':
				g->game_grid[current_row][current_column] = GOAL;
				break;
			case '$':
				g->game_grid[current_row][current_column] = BOX;
				break;
			case '@':
				g->game_grid[current_row][current_column] = PLAYER;
				g->p = (struct Player*)malloc(sizeof(struct Player));
				if (g->p == NULL) {
					perror("Erreur");
					exit(EXIT_FAILURE);
				}
				g->p->x = current_row;
				g->p->y = current_column;
				break;
			case ' ':
				g->game_grid[current_row][current_column] = NONE;
				break;
			}
			current_column += 1;
			buffer += 1;
		}
		current_row += 1;
	}
	// fermeture du fichier
	fclose(file);
}

void display(struct Grid *g)
{
	for (int i = 0; i < g->row_number; i++)
	{
		for (int j = 0; j < g->column_number; j++)
		{
			printf("%c", g->game_grid[i][j]);
		}
		printf("\n");
	}
}

void free_struct_and_player(struct Grid *g)
{
	for (int i = 0; i < g->row_number; i++)
	{
		free(g->game_grid[i]);
	}
	free(g->game_grid);
	free(g->p);
	free(g);
}
