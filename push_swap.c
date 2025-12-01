/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:34:19 by sla-gran          #+#    #+#             */
/*   Updated: 2025/12/01 11:34:19 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*swap(t_stack *a)
{
	t_stack *tmp;

	if(a && a->next)
	{
		tmp = a->next;
		a->next = a->next->next;
		tmp->next = a;
		a = tmp;
	}
	return (a);
}

t_stack	*push(t_stack *a, t_stack *b)
{
	if (b)
	{
		b->next = a;
		a = b;
	}
	return (a);
}

t_stack *rotate(t_stack *a)
{
	t_stack *tmp;
	t_stack *before_last;

	tmp = a;
	while (a->next)
	{
		if (a->next->next)
		{
			before_last = a;
		}
		a = a->next;
	}
	a->next = tmp;
	before_last->next = NULL;
	return (a);
}

t_stack	*reverse_rotate(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	a->next = a;
	ft_lstadd_back(&a, tmp);
	return (a);
}

/*int main(void)
{
	return EXIT_SUCCESS;
}*/
