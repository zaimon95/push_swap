/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:19:14 by sla-gran          #+#    #+#             */
/*   Updated: 2025/12/15 12:19:14 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_args(int argc, char **argv, t_list **stack_a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		parse_one_arg(argv[i], stack_a);
		i++;
	}
}

void	parse_one_arg(char *arg, t_list **stack_a)
{
	int		j;
	char	**split;
	t_list	*tmp;
	int		val;

	if (!arg[0])
		error();
	split = ft_split(arg, ' ');
	j = 0;
	while (split[j])
	{
		if (!is_valid_number(split[j]))
			error();
		val = ft_atoi_safe(split[j]);
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->content == val)
				error();
			tmp = tmp->next;
		}
		ft_lstadd_back(stack_a, ft_lstnew(val));
		j++;
	}
	free_split(split);
}
