/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:38:21 by muayna            #+#    #+#             */
/*   Updated: 2025/06/14 11:49:52 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*source;
	char	*destination;
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	source = (char *)src;
	destination = (char *)dest;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
