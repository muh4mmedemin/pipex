/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 09:19:20 by muayna            #+#    #+#             */
/*   Updated: 2025/06/16 15:49:15 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*destination;

	source = (char *)src;
	destination = (char *)dst;
	if (source < destination)
		while (len--)
			destination[len] = source[len];
	else
		ft_memcpy(destination, source, len);
	return (dst);
}
