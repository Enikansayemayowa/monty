#include "monty.h"
/*
 * swap - The opcode pop removes the top element of the stack
 * @stack: pointer to   line number
 * @line_number: number where to pop from
 * Return: 0
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	   (*stack)->next->n = temp;
}
/*
 * add - The opcode pop removes the top element of the stack
 * @stack: pointer to   line number
 * @line_number: number where to pop from
 * Return: 0
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *next;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	next = (*stack)->next;
	free(*stack);
	next->prev = NULL;
	*stack = next;
}
/*
 * nop - The opcode pop removes the top element of the stack
 * @stack: pointer to   line number
 * @line_number: number where to pop from
 * Return: 0
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
