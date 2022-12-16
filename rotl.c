#include "monty.h"

/**
* rotl - rotates top element to become the last stack element
* @stack: stack to be evaluated
* @lnum: line number
*/
void rotl(stack_t **stack, unsigned int lnum)
{
	stack_t *left;
	stack_t *right;

	(void) lnum;
	if (!stack || !*stack || !(*stack)->next)
		return;

	left = right = *stack;

	while (right->next) /* move the right pointer to the last node */
		right = right->next;
	right->next = left; /* a circle infinite linked list loop */
	left->prev = right;
	*stack = left->next; /* so we cut the link between the 0 and 1 element */
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
