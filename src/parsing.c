/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
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
	if (s[0])
		return (0);
	return (1);
}

long	ft_atoi_safe(char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			sign = -1;
	}
	while (*s)
	{
		res = res * 10 + (*s - '0');
		if ((sign == 1 && res > 2147483647)
			|| (sign == -1 && - res < -2147483648))
			return (2147483648);
		s++;
	}
	return (res * sign);
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

void	parse_one_arg(char *arg, t_list **stack_a)
{
	int		j;
	char	**split;
	long	val;

	if (!arg[0])
		cleanup_and_error(stack_a, NULL);
	split = ft_split(arg, ' ');
	if (!split || !split[0])
		cleanup_and_error(stack_a, split);
	j = 0;
	while (split[j])
	{
		if (!is_valid_number(split[j]))
			cleanup_and_error(stack_a, split);
		val = ft_atoi_safe(split[j]);
		if (val < -2147483648 || val > 2147483647)
			cleanup_and_error(stack_a, split);
		if (check_duplicate(stack_a, (int)val))
			cleanup_and_error(stack_a, split);
		ft_lstadd_back(stack_a, ft_lstnew((int)val));
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