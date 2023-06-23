#include "monty.h"

/**
 * push - pushes an element to the stack
 * @top: A pointer to a pointer to anode
 * @line_number: ....
 */

void push(stack_t **top, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int data;

	if (glob.args == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free(glob.line);
		fclose(glob.file);
		free_struct(top);
		exit(EXIT_FAILURE);
	}
	data = atoi(glob.args);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->prev = NULL;
	new_node->n = data;
	new_node->next = NULL;
	if (*top == NULL)
	{
		*top = new_node;
	}
	else
	{
		new_node->next = *top;
		(*top)->prev = new_node;
		*top = new_node;
	}
}
