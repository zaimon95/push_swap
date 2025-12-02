/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_void.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:53:46 by sla-gran          #+#    #+#             */
/*   Updated: 2025/11/04 10:53:46 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putvoid(void const *p)
{
	unsigned long	adr;
	char			res[17];
	int				i;
	int				count;
	const char		*g_base;

	g_base = "0123456789abcdef";
	if (p == 0)
		return (write(1, "(nil)", 5));
	adr = (unsigned long)p;
	i = 16;
	res[i] = '\0';
	while (adr > 0)
	{
		res[--i] = g_base[adr % 16];
		adr /= 16;
	}
	count = write(1, "0x", 2);
	count += write(1, &res[i], 16 - i);
	return (count);
}
/*
#include <stdio.h>
int main (void)
{
   char const *p = "hello";
 
   printf ("%p\n", (void *) p);
   ft_putvoid (p);
 
   return 0;
}*/
