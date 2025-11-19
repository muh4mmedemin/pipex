/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 15:48:39 by muayna            #+#    #+#             */
/*   Updated: 2025/06/23 13:40:30 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
	return (newstr);
}
