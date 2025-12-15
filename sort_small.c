/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:54:37 by sla-gran          #+#    #+#             */
/*   Updated: 2025/12/15 12:54:37 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_helper(t_list **stack_a, int a, int b, int c)
{
	if (a > b && b < c && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ra(stack_a);
	else if (a < b && b > c && a < c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a < b && b > c && a > c)
		rra(stack_a);
}

void	sort_three(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (stack_size(*stack_a) != 3)
		return ;
	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	sort_three_helper(stack_a, a, b, c);
}

void	rotate_to_min(t_list **stack_a, int min, int index, int size)
{
	if (index <= size / 2)
	{
		while ((*stack_a)->content != min)
			ra(stack_a);
	}
	else
	{
		while ((*stack_a)->content != min)
			rra(stack_a);
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	size;
	int	min;
	int	index;

	size = stack_size(*stack_a);
	while (size > 3)
	{
		min = find_min(*stack_a);
		index = get_position(*stack_a, min);
		rotate_to_min(stack_a, min, index, size);
		pb(stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}

int	find_min(t_list *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}
