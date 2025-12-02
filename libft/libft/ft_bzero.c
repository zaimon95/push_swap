/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 13:58:46 by sla-gran          #+#    #+#             */
/*   Updated: 2025/10/14 13:58:46 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

/*#include <stdio.h>
#include <string.h>   // Pour bzero
#include <unistd.h>   // Pour write si besoin
#include <stdlib.h>   // Pour malloc

void	ft_bzero(void *s, size_t n); // Déclaration de ta fonction perso

void print_buffer(unsigned char *buf, size_t size)
{
	for (size_t i = 0; i < size; i++)
		printf("%02x ", buf[i]);
	printf("\n");
}

int main(void)
{
	size_t	size = 10;
	unsigned char buffer1[10];
	unsigned char buffer2[10];

	// Remplir les deux buffers avec la même valeur
	memset(buffer1, 'A', size);
	memset(buffer2, 'A', size);

	// Appliquer bzero sur buffer1
	bzero(buffer1, 5); // Fonction de la libc
	// Appliquer ft_bzero sur buffer2
	ft_bzero(buffer2, 5); // Ta fonction perso

	printf("bzero result : ");
	print_buffer(buffer1, size);

	printf("ft_bzero result : ");
	print_buffer(buffer2, size);

	// Comparaison manuelle ou via memcmp si tu veux automatiser
	if (memcmp(buffer1, buffer2, size) == 0)
		printf("✅ Les résultats sont identiques.\n");
	else
		printf("❌ Les résultats sont différents.\n");

	return 0;
}*/
