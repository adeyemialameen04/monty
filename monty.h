#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

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
 * struct data - The data struct.
 * @argc: The args count.
 * @argv: The args array.
 * @cmd: The command gotten from getline.
 * @exit_status: The status of each command.
 * @stack: The stack struct.
 * @line_num: Line number.
 */
typedef struct data
{
	char *cmd;
	char **argv;
	int argc;
	int exit_status;
	unsigned int line_num;
	stack_t **stack;
} data_t;

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

extern data_t *glob_data_ptr;
extern FILE *glob_fd_ptr;

data_t initialize_data_struct(void);

/* CUSTOM FUNCTIONS */
char *_div_str(char *str, const char *delim);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);

void _print(int fd, char *printval);
void read_file(char *argv[], data_t *data);
int _monty(int argc, char *argv[]);
int _tokenize_line(data_t *data, const char *delim);

/* STACK OPERATIONS */
void (*get_op_function(char *str))(stack_t **stack, unsigned int line_number);
bool is_empty(stack_t **stack);

/* BASIC STACK OPERATIONS */
void push(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
int stack_list(stack_t **stack);
void nop(stack_t **stack, unsigned int line_number);

/* MATHS STACK OPERATIONS */
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void divide(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);

/* STRING STACK OPERATIONS */
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/*STRING OPERATIONS*/
int _atoi(char *s);
int _strlen(char *s);
char *_strdup(char *str);
char *itoa(int num, char *str);
void trim_whitespace(char *str);

/* FREEING MEMORY */
void _free_argv(data_t *data);
void _free_stack(stack_t **stack);
void cleanup(data_t *data, bool fs);

/* PRINTING ERRORS */
void print_errmsg_invalid_opcode(char *str, data_t *data);
void print_errmsg_cant_open_file(char *filename);
void _print_errmsg_cant_do_op(char *str, char *err_cant);

#endif /* #ifndef _MONTY_H_ */
