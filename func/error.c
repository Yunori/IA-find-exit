#include "../pre.h"

int NbArguments (int argc)
{
	int ret;
	ret = 1;
	if (argc > 4)
		printf("Trop d'arguments on été mis!\n");
	if (argc < 4)
		printf("Il manque des arguments!\n");
	return ret;
}

int CheckNumbers (char** argv)
{
	int ret;
	ret = 0;
	if (isdigit(*argv[1]) == 0)
	{
		printf("Le premier argument doit etre un chiffre\n");
		ret = 1;
	}
	if (isdigit(*argv[2]) == 0)
	{
		printf("Le deuxieme argument doit etre un chiffre\n");
		ret = 1;
	}
	return ret;
}

int Error (int argc, char** argv)
{
	int ret;
	ret = 0;
	if (argc < 4 || argc > 4)
		ret = NbArguments(argc);
	if (argc > 3)
	{
		ret = CheckNumbers(argv);
		FILE * a;
		a = fopen(argv[3], "r");
		if (a == NULL)
		{
			printf("Le fichier est introuvable ou vous n'avez pas les droits\n");
			ret = 1;
		}
	}
	return ret;
}

int CheckMap (char** argv)
{
	int c;
	int check;
	int max;
	FILE * file;
	file = fopen(argv[3], "r");
	max = -1;
	check = 0;
	while((c = fgetc(file)) != EOF)
	{
		if (c != '\n')
			check++;
		if (max < 0 && c == '\n')
			max = check;
		if(c == '\n')
		{
			if (check != max)
				return 1;
			check = 0;
		}
	}
	return 0;
}