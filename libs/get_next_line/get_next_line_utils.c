/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:43:53 by muayna            #+#    #+#             */
/*   Updated: 2025/08/08 14:31:27 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int				i;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	if (uc == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == uc)
		{
			return ((char *)s + i);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		b;
	char	*newstr;
	int		totalstr;

	b = 0;
	i = 0;
	totalstr = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	newstr = malloc(totalstr + 1);
	if (newstr == NULL)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	while (s2[b])
	{
		newstr[i] = s2[b];
		b++;
		i++;
	}
	newstr[i] = '\0';
	free((char *)s1);
	return (newstr);
}

char	*ft_strdup(const char *s)
{
	int		srcsize;
	char	*newstr;

	srcsize = 0;
	while (s[srcsize] != '\n' && s[srcsize] != '\0')
		srcsize++;
	newstr = malloc(srcsize + 1);
	if (newstr == NULL)
		return (NULL);
	srcsize = 0;
	while (s[srcsize] != '\n' && s[srcsize] != '\0')
	{
		newstr[srcsize] = s[srcsize];
		srcsize++;
	}
	newstr[srcsize] = '\0';
	return (newstr);
}
