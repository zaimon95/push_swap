/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:radix.c
/*   radix.c                                            :+:      :+:    :+:   */
========
/*   index.c                                            :+:      :+:    :+:   */
>>>>>>>> b2c34fc51ccd8ff8f83b397197ae41ad27862ff1:index.c
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:radix.c
/*   Created: 2026/01/23 13:27:14 by sla-gran          #+#    #+#             */
/*   Updated: 2026/01/23 13:27:14 by sla-gran         ###   ########.fr       */
========
/*   Created: 2026/01/29 11:26:56 by sla-gran          #+#    #+#             */
/*   Updated: 2026/01/29 11:50:04 by sla-gran         ###   ########.fr       */
>>>>>>>> b2c34fc51ccd8ff8f83b397197ae41ad27862ff1:index.c
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<<< HEAD:radix.c
void	radix_sort(t_list **stack_a, t_list **stack_b)
{

========
static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min
					|| head->content < min->content))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
>>>>>>>> b2c34fc51ccd8ff8f83b397197ae41ad27862ff1:index.c
}
