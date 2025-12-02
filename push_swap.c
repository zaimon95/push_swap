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

void	operations(t_list *a, t_list *b)
{
	if (swap(a))
		ft_printf("sa\n");
	if (swap(b))
		ft_printf("sb\n");
	if (swap(a) && swap(b))
		ft_printf("ss\n");
	if (push(a, &b))
		ft_printf("pa\n");
	if (push(b, &a))
		ft_printf("pb\n");
	if (rotate(a))
		ft_printf("ra\n");
	if (rotate(b))
		ft_printf("rb\n");
	if (rotate(a) && rotate(b))
		ft_printf("rr\n");
	if (reverse_rotate(a))
		ft_printf("rra\n");
	if (reverse_rotate(b))
		ft_printf("rrb\n");
	if (reverse_rotate(a) && reverse_rotate(b))
		ft_printf("rrr\n");
}

/*int main(void)
{
	return EXIT_SUCCESS;
}*/
