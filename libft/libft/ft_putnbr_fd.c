/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 13:55:52 by sla-gran          #+#    #+#             */
/*   Updated: 2025/07/21 10:58:14 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_recursive(int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_recursive(n / 10, fd);
	c = (n % 10) + '0';
	count += write(fd, &c, 1);
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (fd == -1)
		return (0);
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	count += ft_putnbr_recursive(n, fd);
	return (count);
}
