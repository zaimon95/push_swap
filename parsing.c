/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:39:39 by sla-gran          #+#    #+#             */
/*   Updated: 2025/12/02 13:39:39 by sla-gran         ###   ########.fr       */
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

int	ft_atoi_safe(char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -1;
		else
			sign = 1;
	}
	while (*s)
	{
		res = res * 10 + (*s - '0');
		if ((sign == 1 && res > 2147483647)
			|| (sign == -1 && - res < -2147483648))
			ft_error("Error");
		s++;
	}
	return ((int)(res * sign));
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
		ft_error("Error");
	split = ft_split(arg, ' ');
	j = 0;
	while (split[j])
	{
		if (!is_valid_number(split[j]))
			ft_error("Error");
		val = ft_atoi_safe(split[j]);
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->content == val)
				ft_error("Error");
			tmp = tmp->next;
		}
		lst_add_back(stack_a, lst_new(val));
		j++;
	}
	free_split(split);
}
