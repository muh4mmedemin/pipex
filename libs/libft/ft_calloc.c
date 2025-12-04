/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 18:19:29 by muayna            #+#    #+#             */
/*   Updated: 2025/06/26 18:20:36 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (!nmemb || !size)
		return (malloc(0));
	res = malloc(nmemb * size);
	if (!res)
		return (NULL);
	ft_bzero(res, nmemb * size);
	return (res);
}
