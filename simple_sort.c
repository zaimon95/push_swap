/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:29:54 by sla-gran          #+#    #+#             */
/*   Updated: 2026/01/21 10:29:54 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *stack_a)
{
	int	max;
	int	index;
	
	max = INT_MIN;
	index = 0;
	while (stack_a->next)
	{
		if (max < stack_a->content)
		{
			max = stack_a->content;
			index = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	return (index);
}

int find_min(t_list *stack_a)
{
	int	min;
	int	index;
	
	min = INT_MAX;
	index = 0;
	while (stack_a->next)
	{
		if (min > stack_a->content)
		{
			min = stack_a->content;
			index = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	return (index);
}

void	sort_3(t_list *stack_a)
{
	int	index_max;

	index_max = find_max(stack_a);
	if (index_max == 0)
		ra(stack_a);
	else if(index_max == 1)
		rra(stack_a);
	if (stack_a->content > stack_a->next->content)
		sa(stack_a);
}

void sort_4(t_list *stack_a, t_list *stack_b)
{
	int	index_min;
	int	i;

	index_min = find_min(stack_a);
	i = 0;
	while (i < index_min - 1)
	{
		ra(stack_a);
		i++;
	}
	pa(stack_a, stack_b);
	sort_3(stack_a);
	pb(stack_a, stack_b);
}

void	sort_5(t_list *stack_a, t_list *stack_b)
{
	int	index_min;
	int	i;

	i = 0;
	index_min = find_min(stack_a);
	while (i < index_min - 1)
	{
		ra(stack_a);
		i++;
	}
	pa(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pb(stack_a, stack_b);
}
