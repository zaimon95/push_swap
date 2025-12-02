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
# include <stdlib.h>
# include <unistd.h>


t_list  *swap(t_list *a);
t_list	*push(t_list *a, t_list **b);
t_list	*rotate(t_list *a);
t_list	*reverse_rotate(t_list *a);

#endif
