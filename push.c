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
	char *ptr;

	if (glob.args == NULL || *glob.args == '\0' || isspace(*glob.args))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_error(top);
		exit(EXIT_FAILURE);
	}
	for (ptr = glob.args; *ptr != '\0'; ptr++)
	{
		if (!isdigit(*ptr))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_error(top);
			exit(EXIT_FAILURE);
		}
	}
	data = atoi(glob.args);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_struct(top);
		free(glob.line);
		if (glob.file != NULL)
			fclose(glob.file);
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

/**
 * free_error - frees memory incase of errors in the program
 * @top: ....
 */


void free_error(stack_t **top)
{
	free(glob.line);
	free_struct(top);
	fclose(glob.file);
}
