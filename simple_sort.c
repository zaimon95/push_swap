/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:29:54 by sla-gran          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/01/21 10:29:54 by sla-gran         ###   ########.fr       */
=======
/*   Updated: 2026/01/29 11:23:57 by sla-gran         ###   ########.fr       */
>>>>>>> b2c34fc51ccd8ff8f83b397197ae41ad27862ff1
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
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
=======
static int	find_min_index(t_list **stack)
{
	t_list	*head;
	int		min;
	int		min_index;
	int		index;

	head = *stack;
	min = head->index;
	min_index = 0;
	index = 0;
	while (head)
	{
		if (head->index < min)
		{
			min = head->index;
			min_index = index;
		}
		head = head->next;
		index++;
	}
	return (min_index);
}

void	sort_3(t_list **stack_a)
{
	int	a;
	int	b;
	int	c;

	if (ft_lstsize(*stack_a) != 3)
		return ;
	a = (*stack_a)->index;
	b = (*stack_a)->next->index;
	c = (*stack_a)->next->next->index;
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

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = find_min_index(stack_a);
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_3(stack_a);
	pa(stack_a, stack_b);
}

void	sort_5(t_list **stack_a, t_list **stack_b)
{
	int	distance;

	distance = find_min_index(stack_a);
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (is_sorted(stack_a) || ft_lstsize(*stack_a) == 0
		|| ft_lstsize(*stack_a) == 1)
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_3(stack_a);
	else if (size == 4)
		sort_4(stack_a, stack_b);
	else if (size == 5)
		sort_5(stack_a, stack_b);
>>>>>>> b2c34fc51ccd8ff8f83b397197ae41ad27862ff1
}
