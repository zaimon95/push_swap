/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 16:04:10 by sla-gran          #+#    #+#             */
/*   Updated: 2025/10/20 16:04:10 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	size_t	test;
	char	*res;

	test = size * nmemb;
	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (test / size != nmemb)
		return (NULL);
	res = malloc(test);
	if (!res)
		return (NULL);
	while (res[i])
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
