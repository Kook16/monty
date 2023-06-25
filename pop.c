#include "monty.h"

/**
 * pop - removes the top element of the stack
 * @top: ...
 * @line_number: ...
 */

void pop(stack_t **top, unsigned int line_number)
{
	stack_t *node = NULL;

	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_error(top);
		exit(EXIT_FAILURE);
	}
	node = *top;
	*top = (*top)->next;
	if (*top != NULL)
		(*top)->prev = NULL;

	free(node);
}
