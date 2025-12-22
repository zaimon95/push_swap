/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:05:31 by sla-gran          #+#    #+#             */
/*   Updated: 2025/12/17 11:05:31 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *stack_a)
{
	t_list	*temp;

	if(!stack_a || !stack_a->next)
		return ;
	temp->content = stack_a->next->content;
	temp->next = stack_a;
	stack_a = temp;
	ft_printf("sa");
}

void	sb(t_list *stack_b)
{
	t_list	*temp;

	if(!stack_b || !stack_b->next)
		return ;
	temp->content = stack_b->next->content;
	temp->next = stack_b;
	stack_b = temp;
	ft_printf("sb");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;
	t_list	*temp2;

	if (!stack_a || !stack_a->next)
		return ;
	temp->content = stack_a->next->content;
	temp->next = stack_a;
	stack_a = temp;
	if(!stack_b || !stack_b->next)
		return ;
	temp2->content = stack_b->next->content;
	temp2->next = stack_b;
	stack_b = temp2;
	ft_printf("ss");
}

void	pa(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;
	if (!stack_b)
		return ;
	temp = stack_b;
	ft_lst_addfront(&stack_a, temp);
	stack_b = stack_b->next;
	ft_printf("pa");
}

void	pb(t_list *stack_a, t_list *stack_b)
{
	t_list	*temp;
	if (!stack_a)
		return ;
	temp = stack_a;
	ft_lst_addfront(&stack_b, temp);
	stack_a = stack_a->next;
	ft_printf("pb");
}
