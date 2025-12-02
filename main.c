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

int main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	size_t	i;

	i = 0;
	if (argc > 1)
	{
		//malloc a et b de taille argc
		while(argv[i])
		{
			a->content = ft_atoi(argv[i]);
			i++;
			a = a->next;
		}
	}
	else 
		return EXIT_SUCCESS;
	return EXIT_SUCCESS;
}
