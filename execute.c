#include "monty.h"

/**
 * execute - ...
 * @line: ...
 * @line_number: ...
 * @top: ...
 * Return: ...
 */

int execute(char *line, unsigned int line_number, stack_t **top)
{
	instruction_t op_func[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0, flag = 0;
	char *str, *delim = " \t\n";

	str = strtok(line, delim);
	if (str == NULL)
		return (0);
	glob.args = strtok(NULL, delim);
	while (op_func[i].opcode != NULL && str != NULL)
	{
		if (strcmp(str, op_func[i].opcode) == 0)
		{
			flag = 1;
			op_func[i].f(top, line_number);
			break;
		}
		i++;
	}
	if (!flag)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
		exit(EXIT_FAILURE);
	}
	return (1);
}
