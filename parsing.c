/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 14:05:11 by sla-gran          #+#    #+#             */
/*   Updated: 2026/01/06 14:05:11 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// verifier que tout est valide (que des int, pas de doublons, signe valide, pas de liste vide, ...)
// transformer chaque elem en int
// ajouter dans le stack
//
// #atoi
// if((is+or-(str(i)) && isdigit(str(i+1))) || isdigit(str(i)))
// 	atoi(str)
// else
// 	print "error" and stop
// ne pas accepter si 2 signes d'affile
//
// #creation stack
// malloc chaque element de la stack et rajouter a la stack en faisant attention de les mettre dans le bon ordre (add back)
// avant chaque rajout verifier s'il n'est pas deja dans la liste
// while (parcourir la liste)
//	if (pas = a l'element de la liste)
//		"Erreur" + free
// addback(element)
//
// #overflows
// 000000000000000000000001 => "1"
// - => "Error"
// + => "Error"

#include "push_swap.h"

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

void	check_is_number(char *str)
{
	int	i;
	int	ok;

	i = 0;
	ok = 1;
	while ((is_sign(str[0]) && ft_isdigit(i + 1)) || ft_isdigit(i))
	{
		ok = 0;
		i++;
	}
	if (ok == 0)
		ft_atoi(str);
	else
	{
		ft_printf("Erreur");
		return ;
	}
}
