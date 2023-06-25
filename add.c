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
		free_error(top);
		exit(EXIT_FAILURE);
	}
	node = *top;
	sum = node->n + node->next->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = sum;
	free(node);
}
