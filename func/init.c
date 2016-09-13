#include "../pre.h"

void	game(char **argv)
{
  FILE *fp;
  int *size;
  size = asize(fp, argv);
  fill(fp, size[0], size[1], argv);
}

int  *	asize(FILE *fp, char **argv)
{
  int current;
  int currenthsize;
  static int size[2];

  size[0] = 0;
  fp = fopen(argv[3], "r");
  for(currenthsize = 1; !feof(fp); currenthsize++)
    {
      current = fgetc(fp);
      if(current == '\n' && size[1] < currenthsize)
	{
	  size[0]++;
	  size[1] = currenthsize-1;
	  currenthsize = 0;
	}
      if(feof(fp))
	break;
    }
  return size;
}

void	fill(FILE *fp, int y, int x, char **argv)
{
  int map[y][x];
  int *p[y];
  int z;
  struct loop inc;
  struct pos coord;
  fp = fopen(argv[3], "r");
  for(inc.a = 0; inc.a < y; ++inc.a)
    for(inc.z = 0; inc.z < x+1; ++inc.z)
	{
	  inc.current = fgetc(fp);
	  if(inc.current == '#')
	    {
	      coord.stopy = inc.a;
	      coord.stopx = inc.z;
	    }
	  if(inc.current == '@')
	    {
	      coord.starty = inc.a;
	      coord.startx = inc.z;
	    }
	  if(!feof(fp) && inc.current != '\n')
	      map[inc.a][inc.z] = inc.current;
	}
  for(z = 0; z < y; ++z) p[z] = map[z];
  start(p, y, x, coord, argv);
}