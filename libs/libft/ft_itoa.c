/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:13:47 by muayna            #+#    #+#             */
/*   Updated: 2025/06/21 09:58:34 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	mal_size(int n)
{
	int	temp;
	int	size;

	temp = n;
	size = 0;
	while (temp != 0)
	{
		temp /= 10;
		size++;
	}
	return (size);
}

static char	*ftwrite(int n, char *str, int size)
{
	int	temp;

	temp = n;
	if (size == mal_size(n))
		str[0] = '-';
	while (temp != 0)
	{
		str[size] = (temp % 10) + 48;
		temp /= 10;
		size--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		b;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	b = 1;
	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
		b--;
	}
	str = malloc(mal_size(n) + i);
	if (str == NULL)
		return (NULL);
	str = ftwrite(n, str, mal_size(n) - b);
	if (str[0] == '-')
		str[mal_size(n) + 1] = '\0';
	else
		str[mal_size(n)] = '\0';
	return (str);
}
