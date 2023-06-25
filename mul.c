#include "monty.h"

/**
 * mul - adds the top two element of the stack
 * @top: ....
 * @line_number: ...
 */

void mul(stack_t **top, unsigned int line_number)
{
	stack_t *node = NULL;
	int res = 0;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_error(top);
		exit(EXIT_FAILURE);
	}
	node = *top;
	res = node->n * node->next->n;
	*top = (*top)->next;
	(*top)->prev = NULL;
	(*top)->n = res;
	free(node);
}
