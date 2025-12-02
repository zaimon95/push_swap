/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:18:51 by sla-gran          #+#    #+#             */
/*   Updated: 2025/10/15 15:18:51 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#define MAX_CHAR 100
int main()
{
	const char src[50] = "Tutorialspoint";
	char dest[50];
	strcpy(dest,"Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src) + 1);
	printf("After memcpy dest = %s\n", dest);

	char first_str1[] = "Tutorials";
    char sec_str1[] = "Point";

    puts("first_str before memcpy:");
    puts(first_str1);

    // Copy the content of first_str to sec_str
    memcpy(first_str1, sec_str1, sizeof(sec_str1));

    puts("\nfirst_str after memcpy:");
    puts(first_str1);

    char first_str[MAX_CHAR] = "Hello World!";
	char second_str[MAX_CHAR] = "Welcome to Tutorialspoint";

	printf("The Actual Statements:-\n");
	printf("first_str: %s\n", first_str);
	printf("second_str: %s\n", second_str);

	//copying all bytes of second_str to first_str
	memcpy(first_str, second_str, strlen(second_str));
	printf("%lu\n", strlen(second_str));
	printf("%lu\n", strlen(first_str));
	printf("After executing the function memcpy()\n");
	printf("first_str: %s\n", first_str);
	printf("second_str: %s\n", second_str);
	return 0;
}*/
