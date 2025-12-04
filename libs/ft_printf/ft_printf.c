/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 11:46:49 by muayna            #+#    #+#             */
/*   Updated: 2025/08/18 16:49:07 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(va_list args, char c)
{
	char	d;

	if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'c')
	{
		d = va_arg(args, int);
		return (write(1, &d, 1));
	}
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_write_pointer(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_unsigned_putnbr(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return ((ft_decimalto_hexadecimal(va_arg(args, unsigned int), c)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_size;

	va_start(args, str);
	print_size = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_size = print_size + format(args, str[i]);
		}
		else
			print_size = print_size + write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (print_size);
}
