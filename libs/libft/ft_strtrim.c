/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:38:02 by muayna            #+#    #+#             */
/*   Updated: 2025/06/23 13:44:50 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	start(char *s1, char *set)
{
	int	i;
	int	b;
	int	skipsize;
	int	check;

	i = 0;
	skipsize = 0;
	while (s1[i])
	{
		b = 0;
		check = 0;
		while (set[b])
		{
			if (set[b] == s1[i])
			{
				check = 1;
				skipsize++;
				i++;
			}
			b++;
		}
		if (check == 0)
			return (skipsize);
	}
	return (0);
}

static int	end(char *s1, char *set, int s1_size)
{
	int	i;
	int	b;
	int	check;

	b = 0;
	while (s1[b])
	{
		i = 0;
		check = 0;
		while (set[i])
		{
			if (s1[s1_size - 1] == set[i])
			{
				check = 1;
				s1_size--;
			}
			i++;
		}
		b++;
		if (check == 0)
			return (s1_size);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;
	int		malsize;

	if (s1 == NULL)
		return (ft_strdup(""));
	if (set == NULL)
		return (ft_strdup(s1));
	malsize = end((char *)s1, (char *)set, ft_strlen((char *)s1))
		- start((char *)s1, (char *)set) + 1;
	i = 0;
	trimmed = malloc(malsize);
	if (trimmed == NULL)
		return (NULL);
	while (i < malsize - 1)
	{
		trimmed[i] = s1[start((char *)s1, (char *)set) + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
