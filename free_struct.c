#include "monty.h"

/**
 * free_struct - ....
 * @node: ...
 */

void free_struct(stack_t **node)
{
	stack_t *old, *new;

	old = *node;
	while (old->next != NULL)
	{
		new = old;
		old = old->next;
		free(new);
	}
	free(old);
	old = NULL;
	new = NULL;
}
