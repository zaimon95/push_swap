/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:39:39 by sla-gran          #+#    #+#             */
/*   Updated: 2026/02/10 00:22:53 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

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

void	check_duplicate(t_list **stack_a, int val)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->content == val)
		{
			ft_error("Error");
		}
		tmp = tmp->next;
	}
}

void	parse_one_arg(char *arg, t_list **stack_a)
{
	int		j;
	char	**split;
	int		val;

	if (!arg[0])
		ft_error("Error");
	split = ft_split(arg, ' ');
	if (!split || !split[0])
		ft_error("Error");
	j = 0;
	while (split[j])
	{
		if (!is_valid_number(split[j]))
		{
			free_split(split);
			ft_error("Error");
		}
		val = (int)ft_atoi_safe(split[j]);
		check_duplicate(stack_a, val);
		ft_lstadd_back(stack_a, ft_lstnew(val));
		j++;
	}
	free_split(split);
}

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
