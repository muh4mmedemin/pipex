/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muayna <muayna@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:42:00 by muayna            #+#    #+#             */
/*   Updated: 2025/08/15 23:54:19 by muayna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putstr(char *str);
int	ft_write_pointer(void *p);
int	ft_putnbr(int n);
int	ft_unsigned_putnbr(unsigned int n);
int	ft_decimalto_hexadecimal(unsigned int n, char c);

#endif