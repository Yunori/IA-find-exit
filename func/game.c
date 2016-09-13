#include "../pre.h"

void	start(int **map, int y, int x, struct pos coord, char **argv)
{
  int z;
  int *p[y];
  int life;

  life = argv[1][0] - 48;
  for(z = 0; z < y; ++z) p[z] = map[z];
  affmap(p, y, x);
  while(coord.starty != coord.stopy || coord.startx != coord.stopx)
    {
      if(life == 0)
	break;
      for(z = 0; z < y; ++z) p[z] = map[z];
      map[coord.starty][coord.startx] = '*';
      if(coord.starty != coord.stopy)
		movey(&coord);
      else if(coord.startx != coord.stopx)
		movex(&coord);
      changelife(&life, argv, p, coord);
      map[coord.starty][coord.startx] = '@';
	  affmap(p, y, x);
    }
  if(life != 0 || (life == 0 && (coord.starty == coord.stopy && coord.startx == coord.stopx)))
    printf("%s", "Gagne");
  else
    printf("%s", "Perdu");
}

void movex(struct pos *coord)
{
  if(coord->startx > coord->stopx)
    coord->startx += -1;
  else if(coord->startx < coord->stopx)
    coord->startx += 1;
}

void movey(struct pos *coord)
{
  if(coord->starty > coord->stopy)
    coord->starty += -1;
  else if(coord->starty < coord->stopy)
    coord->starty += 1;
}

void changelife(int *life, char **argv, int **map, struct pos coord)
{
  if(map[coord.starty][coord.startx] == '+')
    *life += argv[2][0] - 48;
  *life += -1;
  printf("%s%d%s", "il vous reste ", *life, " vie");
}

void affmap(int **map, int y, int x)
{
  int a;
  int z;
  for(a = 0; a < y; ++a)
    for(z = 0; z < x; ++z)
      {
	if(z % x == 0)
	  printf("%c", '\n');
	printf("%c", map[a][z]);
      }
  printf("%c", '\n');
  printf("%c", '\n');
}
