/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sla-gran <sla-gran@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:23:26 by sla-gran          #+#    #+#             */
/*   Updated: 2025/10/24 14:23:26 by sla-gran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(char const *str, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

char	*ft_strndup(char const *str, size_t len)
{
	char	*res;
	size_t	i;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	**free_test(char **strs, int j)
{
	while (j > 0)
		free(strs[--j]);
	free(strs);
	return (NULL);
}

char	**ft_fill_split(char **strs, char const *s, char c)
{
	size_t	i;
	size_t	start;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			strs[j] = ft_strndup(s + start, i - start);
			if (!strs[j++])
				return (free_test(strs, j));
		}
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!strs)
		return (NULL);
	return (ft_fill_split(strs, s, c));
}
/*
#include <stdio.h>
#include <stdlib.h>
#include "libft.h" // Make sure this includes your ft_split prototype

int main(void)
{
	char **strs = ft_split("", '^');

	if (!strs)
		return (1);
	int i = -1;
	while (strs[++i])
		printf("'%s'\n", strs[i]);
	printf("'%s'\n", strs[i]);

	for (int i = 0; strs[i]; i++)
		free(strs[i]);
	free(strs);

	return EXIT_SUCCESS;
}

void	print_split(char **split)
{
	int	i = 0;

	if (!split)
	{
		printf("Split returned NULL\n");
		return;
	}
	while (split[i])
	{
		printf("str[%d] = \"%s\"\n", i, split[i]);
		i++;
	}
	printf("Total: %d strings\n", i);
}/home/sla-gran/francinette/temp/libft/fsoares/error.log


int	main(void)
{
	char **result;

	printf("=== Test 1 ===\n");
	result = ft_split("hello world this is 42", ' ');
	print_split(result);
	
	// Free memory
	for (int i = 0; result[i]; i++)
		free(result[i]);
	free(result);

	printf("\n=== Test 2 ===\n");
	result = ft_split(",,,split,,,this,,,string,,,", ',');
	print_split(result);
	for (int i = 0; result[i]; i++)
		free(result[i]);
	free(result);

	printf("\n=== Test 3 ===\n");
	result = ft_split("", ' ');
	print_split(result);
	if (result)
	{
		for (int i = 0; result[i]; i++)
			free(result[i]);
		free(result);
	}

	printf("\n=== Test 4 ===\n");
	result = ft_split("no_delimiters_here", ',');
	print_split(result);
	for (int i = 0; result[i]; i++)
		free(result[i]);
	free(result);

	printf("\n=== Test 5 ===\n");
	result = ft_split(NULL, ' ');
	print_split(result);

	return (0);
}*/
