/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:33:07 by sla-gran          #+#    #+#             */
/*   Updated: 2025/10/20 16:33:07 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	len = ft_strlen(s);
	if (fd != -1)
	{
		if (s == NULL)
			return (write (fd, "(null)", 6));
		else
			write(fd, s, len);
	}
	return ((int)len);
}
