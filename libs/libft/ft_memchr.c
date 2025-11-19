/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:25:21 by muayna            #+#    #+#             */
/*   Updated: 2025/06/21 09:59:47 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	size_t	i;
	char	uc;

	uc = (unsigned int)c;
	i = 0;
	ptr = (char *)s;
	while (i < n)
	{
		if (ptr[i] == uc)
			return ((unsigned char *)&ptr[i]);
		i++;
	}
	return (NULL);
}
