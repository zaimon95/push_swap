/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:54:31 by sla-gran          #+#    #+#             */
/*   Updated: 2026/02/10 00:09:19 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **stack_a)
{
	t_list	*temp;
	t_list	*min;
	int		has_min;

	has_min = 0;
	temp = *stack_a;
	min = NULL;
	if (temp)
	{
		while (temp)
		{
			if ((temp->index == -1)
				&& (!has_min || temp->content < min->content))
			{
				min = temp;
				has_min = 1;
			}
			temp = temp->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack_a)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack_a);
	while (head)
	{
		head->index = index;
		index++;
		head = get_next_min(stack_a);
	}
}
