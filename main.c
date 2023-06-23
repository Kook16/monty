#include "monty.h"
glob_t glob = {NULL, NULL, NULL};
/**
 * main - Entry point
 * @argv: Array of string
 * @argc: Number of arguments passed to the commandline
 * Return: 0 for sucess
 */

int main(int argc, char *argv[])
{
	unsigned int line_number = 1;
	FILE *file;
	char *line;
	stack_t *top = NULL;
	size_t n = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &n, file) != -1)
	{
		if (execute(line, line_number, &top) == 0)
		{
			line_number++;
			continue;
		}

	}
	free_struct(&top);
	free(line);
	fclose(file);
	exit(EXIT_SUCCESS);
}
