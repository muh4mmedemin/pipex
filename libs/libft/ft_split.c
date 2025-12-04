/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 22:49:54 by muayna            #+#    #+#             */
/*   Updated: 2025/12/02 15:38:53 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "../garbage_collector/gb.h"

static int	ft_free(char **str, int b)
{
	while (b != -1)
	{
		free(str[b]);
		b--;
	}
	free(str);
	return (0);
}

static int	countw(char *s, char sep)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i + 1] == sep && s[i] != sep) || (s[i + 1] == '\0'
				&& s[i] != sep))
			word++;
		i++;
	}
	return (word);
}

static int	chr_size(char *s, char sep, int *e)
{
	int	size;

	size = 0;
	while (s[*e])
	{
		while (s[*e] == sep)
			(*e)++;
		size = 0;
		while (s[*e] != sep && s[*e] != '\0')
		{
			(*e)++;
			size++;
			if (s[*e] == sep)
				return (size);
		}
	}
	return (size);
}

static void	fill(int *e, char *s, char sep, char **str)
{
	int	i;
	int	b;

	i = 0;
	while (str[i] != NULL)
	{
		while (s[*e] == sep)
			(*e)++;
		b = 0;
		while (s[*e] != sep && s[*e] != '\0')
		{
			str[i][b] = s[*e];
			(*e)++;
			b++;
			str[i][b] = '\0';
		}
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	int		wr_size;
	char	**str;
	int		e;
	int		b;

	b = 0;
	e = 0;
	wr_size = countw((char *)s, c);
	str = ft_malloc(sizeof(char *) * (wr_size + 1), 0);
	if (str == NULL)
		return (NULL);
	str[wr_size] = NULL;
	while (b < wr_size)
	{
		str[b] = ft_malloc(chr_size((char *)s, c, &e) + 1, 0);
		if (str[b] == NULL)
		{
			ft_free(str, b);
			return (NULL);
		}
		b++;
	}
	e = 0;
	fill(&e, (char *)s, c, str);
	return (str);
}
