#include "monty.h"

/**
 * add - adds the top two element of the stack
 * @top: ....
 * @line_number: ...
 */

void add(stack_t **top, unsigned int line_number)
{
	stack_t *node = NULL;
	int sum = 0;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free(glob.line);
		free_struct(top);
		fclose(glob.file);
		exit(EXIT_FAILURE);
	}
	node = *top;
	sum = node->n + node->next->n;
	node->next->n = sum;
	pop(top, line_number);
}
