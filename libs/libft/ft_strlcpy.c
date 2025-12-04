/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:39:51 by muayna            #+#    #+#             */
/*   Updated: 2025/06/12 20:33:58 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int		srcsize;
	size_t	i;

	i = 0;
	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	if (size == 0)
		return (srcsize);
	if (dst == NULL)
		return (srcsize);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srcsize);
}
