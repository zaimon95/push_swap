/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:32:32 by sla-gran          #+#    #+#             */
/*   Updated: 2025/10/25 10:54:58 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	s = (const char *)src;
	d = (char *)dest;
	i = -1;
	if (src < dest)
		while (n--)
			d[n] = s[n];
	else
		while (++i < n)
			d[i] = s[i];
	return (dest);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = {65, 66, 67, 68, 69, 0, 45};
	char s0[] = { 0,  0,  0,  0,  0,  0, 0};
	char sCpy[] = {65, 66, 67, 68, 69, 0, 45};
	char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	char sResult2[] = {67, 67, 68, 68, 69, 0, 45};

	char * str = (char *) ft_memmove(s0, s, 7);
	printf("%s\n", str);
	return EXIT_SUCCESS;
}*/
