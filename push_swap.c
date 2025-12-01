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

	if(a || a->next)
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
	//mettre l'avant dernier comme dernier
	ft_lstadd_front(&a, ft_lstlast(a));
}

/*int main(void)
{
	return EXIT_SUCCESS;
}*/
