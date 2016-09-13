#include "pre.h"

int main (int argc, char** argv)
{
	if (Error(argc, argv) == 0)
	{
		if (CheckMap(argv) == 0)
			game(argv);
		else
			printf("La map ne respecte pas les conditions,\nLisez le readme.txt pour plus d'informations.\n");
	}
	return 0;
}