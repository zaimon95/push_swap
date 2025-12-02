/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 10:32:05 by sla-gran          #+#    #+#             */
/*   Updated: 2025/10/31 10:32:05 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	if_cond(const char *s, size_t i, va_list args)
{
	if (s[i] == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (s[i] == 'd')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (s[i] == 's')
		return (ft_putstr_fd(va_arg(args, char *), 1));
	else if (s[i] == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (s[i] == 'i')
		return (ft_putnbr_fd(va_arg(args, int), 1));
	else if (s[i] == 'x')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), 0));
	else if (s[i] == 'X')
		return (ft_putnbr_hexa(va_arg(args, unsigned int), 1));
	else if (s[i] == '%')
		return (ft_putchar_fd('%', 1));
	else if (s[i] == 'p')
		return (ft_putvoid(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		count;
	va_list	args;
	size_t	i;

	va_start(args, s);
	i = 0;
	count = 0;
	if (s == NULL)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += if_cond(s, i, args);
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
