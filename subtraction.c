#include "monty.h"
/*
 * sub - sub subtracts the top element of the stack from the second top element
 * @stack: pointer to   line number
 * @line_number: number where to pop from
 * Return: 0
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	next = (*stack)->next;
	free(*stack);
	next->prev = NULL;
	*stack = next;
}
/*
 * divide - The opcode pop removes the top element of the stack
 * @stack: pointer to   line number
 * @line_number: number where to pop from
 * Return: 0
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	next = (*stack)->next;
	free(*stack);
	next->prev = NULL;
	*stack = next;
}
/*
 * mul - The opcode pop removes the top element of the stack
 * @stack: pointer to   line number
 * @line_number: number where to pop from
 * Return: 0
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	next = (*stack)->next;
	free(*stack);
	next->prev = NULL;
	*stack = next;
}
/*
 * mod - The opcode pop removes the top element of the stack
 * @stack: pointer to   line number
 * @line_number: number where to pop from
 * Return: 0
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	next = (*stack)->next;
	free(*stack);
	next->prev = NULL;
	*stack = next;
}
