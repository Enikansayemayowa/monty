#include "monty.h"
/*
 * push - The opcode push pushes an element to the stack
 * @stack: ponter to the pointer
 * @number: line number to the item to push to
 * @value: value to push to
 * Return: 0
 */
void push(stack_t **stack, int value)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}
/*
 * pall - The opcode pall prints all the values on the stack, starting from the top of the stack.
 * @stack: ponter to the pointer
 * Return: 0
 */
void pall(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/*
 * pint - Implement the pint opcode.
 * @stack: ponter to the pointer
 * @number: line number to the item to push to
 * Return: 0
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/*
 * pop - The opcode pop removes the top element of the stack
 * @stack: pointer to   line number
 * @line_number: number where to pop from
 * Return: 0
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	next = (*stack)->next;
	free(*stack);
	*stack = next;
	if (next != NULL)
	{
		next->prev = NULL;
	}
}

