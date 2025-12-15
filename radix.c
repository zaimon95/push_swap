/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:56:05 by sla-gran          #+#    #+#             */
/*   Updated: 2025/12/15 12:56:05 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_simplified_index(t_list *stack, int value)
{
	int		index;
	t_list	*tmp;

	index = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->content < value)
			index++;
		tmp = tmp->next;
	}
	return (index);
}

int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

void	radix_sort_bit(t_list **stack_a, t_list **stack_b, int i, int size)
{
	int	j;
	int	num;

	j = 0;
	while (j < size)
	{
		num = get_simplified_index(*stack_a, (*stack_a)->content);
		if (((num >> i) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		j++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_bits;
	int	size;
	int	i;

	size = stack_size(*stack_a);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		radix_sort_bit(stack_a, stack_b, i, size);
		i++;
	}
}
