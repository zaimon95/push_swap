/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:27:31 by sla-gran          #+#    #+#             */
/*   Updated: 2025/10/20 15:27:31 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i <= len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && big[i + j] && i + j < len)
		{
			if (!little[j])
				return ((char *) &big[i]);
			j++;
		}
		if (!little[j])
			return ((char *) &big[i]);
		i++;
	}
	if (!little[0])
		return ((char *) big);
	return (NULL);
}
/*
#include <stdio.h>
int	main(void)
{
	char *s1 = "bonjour je cherche to find. tu l'as vu?";
	char *s2 = "to find";

	printf("%s\n", ft_strnstr(s1, s2, 5));
	printf("%s\n", ft_strnstr(s1, s2, 15));
	printf("%s\n", ft_strnstr(s1, s2, 25));
	printf("%s\n", ft_strnstr(s1, s2, 1));
	printf("%s\n", ft_strnstr(s1, s2, 0));
	printf("%s\n", ft_strnstr(s1, s2, 100));
	printf("%s\n", ft_strnstr(s1, "", 5));
}*/
