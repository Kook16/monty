#include "monty.h"

/**
 * pall - prints the element on the stack
 * @top: ....
 * @line_number: ....
 */

void pall(stack_t **top, unsigned int line_number)
{
	stack_t *head;

	(void)line_number;
	if (*top == NULL)
		return;
	head = *top;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
