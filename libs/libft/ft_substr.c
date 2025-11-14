/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 14:47:34 by muayna            #+#    #+#             */
/*   Updated: 2025/06/17 16:29:22 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	b;
	size_t	size;

	b = 0;
	i = 0;
	size = ft_strlen(s);
	if (len == 0 || s == NULL || start > size)
		return (ft_strdup(""));
	if (len > size - start)
		b = size - start;
	else
		b = len;
	substr = malloc(b + 1);
	if (substr == NULL)
		return (NULL);
	while (start < size && i < b)
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
