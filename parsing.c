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

t_list	**parsing(int argc, char *argv[])

while (i < argc)
{
	t_list *new = ft_lstnew(argv[i]);
	ft_lstaddback(&list, new);
	i++;
}
