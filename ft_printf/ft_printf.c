/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:14:53 by pzaw              #+#    #+#             */
/*   Updated: 2024/07/22 16:14:53 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_check(va_list ap, char c)
{
	int	r;

	r = 0;
	if (c == 'c')
		r = ft_putchar(va_arg(ap, int));
	else if (c == 's')
		r = ft_putstr(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		r = ft_putnbr(va_arg(ap, int));
	else if (c == 'u')
		r = ft_putunbr(va_arg(ap, unsigned int));
	else if (c == 'x')
		r = ft_puthex_low(va_arg(ap, unsigned int));
	else if (c == 'X')
		r = ft_puthex_up(va_arg(ap, unsigned int));
	else if (c == 'p')
		r += ft_putaddress(0, va_arg(ap, unsigned long long));
	else if (c == '%')
		r = ft_putchar('%');
	return (r);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		r;
	va_list	ap;

	va_start(ap, str);
	r = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				r += ft_format_check(ap, str[++i]);
		}
		else
			r += ft_putchar(str[i]);
		i++;
	}
	va_end(ap);
	return (r);
}
