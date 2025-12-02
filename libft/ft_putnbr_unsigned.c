/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:49:17 by sla-gran          #+#    #+#             */
/*   Updated: 2025/11/05 13:49:17 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int a)
{
	int		count;
	char	c;

	count = 0;
	if (a >= 10)
		count += ft_putnbr_unsigned(a / 10);
	c = a % 10 + '0';
	count += write(1, &c, 1);
	return (count);
}
