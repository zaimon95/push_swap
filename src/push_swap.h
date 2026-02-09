/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 11:06:13 by sla-gran          #+#    #+#             */
/*   Updated: 2026/01/29 11:14:51 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/libft/libft.h"
# include <limits.h>

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

void	ft_error(char *msg);
void	ft_free(char **str);
void	free_stack(t_list **stack);
void	parse_args(int argc, char **argv, t_list **stack_a);
void	parse_one_arg(char *arg, t_list **stack_a);

void	index_stack(t_list **stack);
int		is_sorted(t_list **stack);

void	simple_sort(t_list **stack_a, t_list **stack_b);
void	sort_3(t_list **stack_a);
void	sort_4(t_list **stack_a, t_list **stack_b);
void	sort_5(t_list **stack_a, t_list **stack_b);

void	radix_sort(t_list **stack_a, t_list **stack_b);

#endif
