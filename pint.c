#include "monty.h"

/**
 * pint - prints the top element on the statck
 * @top: ....
 * @line_number: ...
 */

void pint(stack_t **top, unsigned int line_number)
{
	(void)line_number;
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free(glob.line);
		fclose(glob.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}
