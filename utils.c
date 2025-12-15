/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:57:14 by sla-gran          #+#    #+#             */
/*   Updated: 2025/12/15 12:57:14 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_list *stack, int value)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->content == value)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}
