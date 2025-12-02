/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:34:34 by sla-gran          #+#    #+#             */
/*   Updated: 2025/11/04 10:34:34 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long n, int upper)
{
	char	*symbol;
	int		len;

	if (upper)
		symbol = "0123456789ABCDEF";
	else
		symbol = "0123456789abcdef";
	len = 0;
	if (n == 0)
		return (ft_putchar_fd('0', 1));
	if (n >= 16)
		len += ft_putnbr_hexa(n / 16, upper);
	len += ft_putchar_fd(symbol[n % 16], 1);
	return (len);
}
