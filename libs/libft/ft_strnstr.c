/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:26:04 by muayna            #+#    #+#             */
/*   Updated: 2025/06/21 10:01:46 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		ltlsize;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	if (*big == 0)
		return (NULL);
	while (i < len)
	{
		ltlsize = 0;
		while (big[i + ltlsize] == little[ltlsize] && i + ltlsize < len)
		{
			if (little[ltlsize + 1] == '\0')
			{
				return ((char *)big + i);
			}
			ltlsize++;
		}
		i++;
	}
	return (NULL);
}
