#include "monty.h"
/**
 * swap - swaps the first two element of the stack
 * @top: ...
 * @line_number: ...
 */

void swap(stack_t **top, unsigned int line_number)
{
	stack_t *node = NULL;
	int x;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		free_error(top);
		exit(EXIT_FAILURE);
	}
	node = *top;
	x = node->n;
	node->n = node->next->n;
	node->next->n = x;
}
