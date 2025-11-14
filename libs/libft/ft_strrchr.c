/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:27:43 by muayna            #+#    #+#             */
/*   Updated: 2025/06/16 17:04:45 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(char const *s, int c)
{
	int	srcsize;
	int	uc;

	uc = (unsigned char)c;
	srcsize = 0;
	while (s[srcsize])
		srcsize++;
	while (srcsize >= 0)
	{
		if (s[srcsize] == uc)
		{
			return ((char *)s + srcsize);
		}
		srcsize--;
	}
	return (NULL);
}
