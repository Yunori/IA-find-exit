#ifndef PRE_H
#define PRE_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct pos
{
  int starty;
  int startx;
  int stopy;
  int stopx;
};

struct loop
{
  int a;
  int z;
  int current;
};

int		NbArguments (int argc);
int		CheckNumbers (char** argv);
int		Error (int argc, char** argv);
int		CheckMap (char** argv);
void	game(char **argv);
int  *	asize(FILE *fp, char **argv);
void	fill(FILE *fp, int y, int x, char **argv);
void	start(int **map, int y, int x, struct pos coord, char **argv);
void	affmap(int **map, int y, int x);
void	movey(struct pos *coord);
void    movex(struct pos *coord);
void	changelife(int *life, char **argv, int **map, struct pos coord);

#endif
