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

t_list	*swap(t_list *a)
{
	t_list	*tmp;

	if (a && a->next)
	{
		tmp = a->next;
		a->next = tmp->next;
		tmp->next = a;
		a = tmp;
	}
	return (a);
}

t_list	*push(t_list *a, t_list **b)
{
	t_list	*tmp;

	if (*b)
	{
		tmp = (*b)->next;
		(*b)->next = a;
		a = *b;
		*b = tmp;
	}
	return (a);
}

t_list	*rotate(t_list *a)
{
	t_list	*first;
	t_list	*last;

	if (!a || !a->next)
		return (a);
	first = a;
	a = a->next;
	first->next = NULL;
	last = ft_lstlast(a);
	ft_lstadd_back(&a, first);
	return (a);
}

t_list	*reverse_rotate(t_list *a)
{
	t_list	*prev;
	t_list	*last;

	if (!a || !a->next)
		return (a);
	prev = NULL;
	last = a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	ft_lstadd_front(&a, last);
	return (a);
}

/*int main(void)
{
	return EXIT_SUCCESS;
}*/
