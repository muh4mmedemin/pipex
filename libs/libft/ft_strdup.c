/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 12:36:21 by muayna            #+#    #+#             */
/*   Updated: 2025/06/16 19:53:23 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	int		srcsize;
	char	*newstr;

	srcsize = 0;
	while (s[srcsize])
		srcsize++;
	newstr = malloc(srcsize + 1);
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
