/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:40:53 by muayna            #+#    #+#             */
/*   Updated: 2025/08/19 17:58:51 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		i += write (1, "(null)", 6);
		return (i);
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_write_pointer(void *p)
{
	unsigned long	dec;
	long long		k[32];
	long long		i;
	int				print_count;

	dec = (unsigned long)p;
	print_count = 0;
	i = 0;
	if (p == NULL)
		return (print_count + write (1, "(nil)", 5));
	while (dec > 0)
	{
		k[i] = dec % 16;
		dec /= 16;
		i++;
	}
	i--;
	print_count += write(1, "0x", 2);
	while (i >= 0)
	{
		print_count += write(1, &"0123456789abcdef"[k[i]], 1);
		i--;
	}
	return (print_count);
}

int	ft_putnbr(int n)
{
	int	print_count;
	int	temp;

	print_count = 0;
	if (n == 0)
		print_count++;
	if (n < 0 && (n != -2147483648))
	{
		n = -n;
		write(1, "-", 1);
		print_count++;
	}
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		print_count++;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	if (n != -2147483648)
		write(1, &"0123456789"[n % 10], 1);
	else
		print_count += write(1, "-2147483648", 11);
	return (print_count);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	int				print_count;
	unsigned int	temp;

	print_count = 0;
	if (n == 0)
		print_count++;
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		print_count++;
	}
	if (n > 9)
		ft_unsigned_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	return (print_count);
}

int	ft_decimalto_hexadecimal(unsigned int n, char c)
{
	long long	k[32];
	int			i;
	int			print_count;

	print_count = 0;
	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	while (n > 0)
	{
		k[i] = n % 16;
		n /= 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		if (c == 'x')
			print_count += write(1, &"0123456789abcdef"[k[i]], 1);
		else if (c == 'X')
			print_count += write(1, &"0123456789ABCDEF"[k[i]], 1);
		i--;
	}
	return (print_count);
}
