#include "monty.h"

/**
 * div - adds the top two element of the stack
 * @top: ....
 * @line_number: ...
 */

void divide(stack_t **top, unsigned int line_number)
{
	stack_t *node = NULL;
	int res = 0;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_error(top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_error(top);
		exit(EXIT_FAILURE);
	}
	node = *top;
	res = node->next->n / node->n;
	pop(top, line_number);
	(*top)->n = res;
}
