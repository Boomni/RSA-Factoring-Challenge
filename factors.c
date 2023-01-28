#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * main - Factorize as many numbers into a product of 2 smaller numbers
 *
 * @argc: number of arguments
 * @argv: command line argument or file supplied
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int i;
	int x, y;
	int num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, fp)) != -1)
	{
		num = atoi(line);
		for (i = 2; i <= num; i++)
		{
			if (num % i == 0)
			{
				x = i;
				y = num / i;
				printf("%d = %d * %d\n", num, y, x);
				break;
			}
		}
	}
	free(line);
	fclose(fp);
	return (0);
}
