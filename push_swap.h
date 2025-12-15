/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:34:25 by sla-gran          #+#    #+#             */
/*   Updated: 2025/12/01 11:34:25 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/ft_printf.h"
# include "libft/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	parse_args(int argc, char **argv, t_list **stack_a);
void	parse_one_arg(char *arg, t_list **stack_a);
int		is_sorted(t_list *stack);
int		stack_size(t_list *stack);
void	push_swap(t_list **stack_a, t_list **stack_b);
int		is_valid_number(char *s);
int		ft_atoi_safe(char *s);
void	free_split(char **split);
void	error(void);
int		get_simplified_index(t_list *stack, int value);
int		get_max_bits(int size);
void	radix_sort_bit(t_list **stack_a, t_list **stack_b, int i, int size);
void	radix_sort(t_list **stack_a, t_list **stack_b);
void	sort_three_helper(t_list **stack_a, int a, int b, int c);
void	sort_three(t_list **stack_a);
void	rotate_to_min(t_list **stack_a, int min, int index, int size);
void	sort_five(t_list **stack_a, t_list **stack_b);
int		find_min(t_list *stack);
int		get_position(t_list *stack, int value);

#endif
