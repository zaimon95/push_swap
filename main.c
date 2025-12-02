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

//parsing function

int main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	size_t	i;

	i = 0;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
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
