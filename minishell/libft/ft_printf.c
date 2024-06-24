/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shmohamm <shmohamm@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:26:50 by mmassarw          #+#    #+#             */
/*   Updated: 2024/06/24 10:05:31 by shmohamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long nbr, long long len, char *base, int *i)
{
	*i += 1;
	if (nbr < 0)
	{
		ft_putchar_fd('-', STDOUT_FILENO);
		ft_putnbr_base(-nbr, len, base, i);
	}
	else
	{
		if (nbr > (len - 1))
		{
			ft_putnbr_base((nbr / len), len, base, i);
		}
		ft_putchar_fd(base[(nbr % len)], STDOUT_FILENO);
	}
}

void	ft_uputnbr(unsigned long nbr, unsigned long len, char *base, int *i)
{
	*i += 1;
	if (nbr > (len - 1))
	{
		ft_putnbr_base((nbr / len), len, base, i);
	}
	ft_putchar_fd(base[(nbr % len)], STDOUT_FILENO);
}

int	ft_printf_flag(va_list ptr, const char *arg, int *len)
{
	if (*arg == 'c')
		*len += ft_putchar_fd(va_arg(ptr, int), STDOUT_FILENO);
	else if (*arg == 's')
		*len += ft_putstr_fd(va_arg(ptr, char *), STDOUT_FILENO);
	else if (*arg == 'p')
	{
		*len += ft_putstr_fd("0x", STDOUT_FILENO);
		ft_uputnbr(va_arg(ptr, unsigned long), 16, HEXL, len);
	}
	else if (*arg == 'd')
		ft_putnbr_base(va_arg(ptr, int), 10, DEC, len);
	else if (*arg == 'i')
		ft_putnbr_base(va_arg(ptr, int), 10, DEC, len);
	else if (*arg == 'u')
		ft_uputnbr(va_arg(ptr, unsigned int), 10, DEC, len);
	else if (*arg == 'x')
		ft_uputnbr(va_arg(ptr, unsigned int), 16, HEXL, len);
	else if (*arg == 'X')
		ft_uputnbr(va_arg(ptr, unsigned int), 16, HEXU, len);
	else if (*arg == '%')
		*len += ft_putchar_fd(*arg, STDOUT_FILENO);
	return (0);
}

/**
 * @brief Has the combined functionality of ft_putchar_fd, ft_putstr_fd, and
 * ft_putnbr_fd with choice of hexadecimal or decimal.
 * 
 * @param arg 
 * @param ... 
 * @return The number of characters written to the stdout
 */
int	ft_printf(const char *arg, ...)
{
	va_list	ptr;
	int		len;

	len = 0;
	va_start(ptr, arg);
	while (*arg)
	{
		if (*arg == '%')
		{
			arg++;
			len += ft_printf_flag(ptr, arg, &len);
		}
		else
			len += ft_putchar_fd(*arg, STDOUT_FILENO);
		arg++;
	}
	return (len);
}
