/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:36:21 by muayna            #+#    #+#             */
/*   Updated: 2025/12/04 23:24:52 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../garbage_collector/gb.h"

char	*ft_strdup(const char *s)
{
	int		srcsize;
	char	*newstr;

	srcsize = 0;
	while (s[srcsize])
		srcsize++;
	newstr = ft_malloc(srcsize + 1, 0);
	if (newstr == NULL)
		return (NULL);
	srcsize = 0;
	while (s[srcsize])
	{
		newstr[srcsize] = s[srcsize];
		srcsize++;
	}
	newstr[srcsize] = '\0';
	return (newstr);
}
