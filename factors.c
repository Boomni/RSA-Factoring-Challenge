#include "factors.h"

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
	long long int  i, num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: factors <file>\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("Error: unable to open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fscanf(fp, "%lld", &num) != EOF)
	{
		for (i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				printf("%lld = %lld * %lld\n", num, num / i, i);
				break;
			}
		}
	}
	fclose(fp);
	return (0);
}
