/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:02:19 by sla-gran          #+#    #+#             */
/*   Updated: 2026/02/16 13:02:19 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	check_duplicate(t_list **stack_a, int val)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->content == val)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	cleanup_and_error(t_list **stack_a, char **split)
{
	free_split(split);
	free_stack_simple(stack_a);
	ft_error("Error");
}
