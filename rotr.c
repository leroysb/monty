#include "monty.h"

/**
* rotr - rotates last element to become the top stack element
* @stack: stack to be evaluated
* @lnum: line number
*/
void rotr(stack_t **stack, unsigned int lnum)
{
	stack_t *bottom;
	stack_t *prev;

	(void) lnum;
	if (!stack || !*stack || !(*stack)->next)
		return;

	bottom = *stack;

	while (bottom->next)
		bottom = bottom->next;

	prev = bottom->prev;
	bottom->next = *stack;
	bottom->prev = NULL;
	prev->next = NULL;
	(*stack)->prev = bottom;
	*stack = bottom;
}
