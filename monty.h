#ifndef MONTY_H
#define MONTY_H
/* lib */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>
#include <ctype.h>


typedef struct glob_s
{
	char *args;
	char *line;
	FILE *file;
} glob_t;

extern glob_t glob;
/* Struct declarartion */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* function declaration */
void push(stack_t **top, unsigned int line_number);
void pall(stack_t **top, unsigned int line_number);
void pint(stack_t **top, unsigned int line_number);
void add(stack_t **top, unsigned int line_number);
void nop(stack_t **top, unsigned int line_number);
void swap(stack_t **top, unsigned int line_number);
void mul(stack_t **top, unsigned int line_number);
void sub(stack_t **top, unsigned int line_number);
int isInteger(char *str);
char **split_string(char *line);
void free_struct(stack_t **top);
void pop(stack_t **top, unsigned int line_number);
void nop(stack_t **top, unsigned int line_number);
int execute(char *line, unsigned line_number, stack_t **top);
void free_error(stack_t **top);
#endif
