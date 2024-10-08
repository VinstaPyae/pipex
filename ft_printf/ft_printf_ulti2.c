/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ulti2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:14:44 by pzaw              #+#    #+#             */
/*   Updated: 2024/07/22 16:14:44 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_low(unsigned int nb)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (nb > 15)
	{
		i += ft_puthex_low(nb / 16);
		i += ft_putchar(base[nb % 16]);
	}
	else
		i += ft_putchar(base[nb % 16]);
	return (i);
}

int	ft_puthex_up(unsigned int nb)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (nb > 15)
	{
		i += ft_puthex_up(nb / 16);
		i += ft_putchar(base[nb % 16]);
	}
	else
		i += ft_putchar(base[nb % 16]);
	return (i);
}

int	ft_putaddress(int flag, unsigned long long nb)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (flag == 0)
	{
		if (nb == 0)
		{
			i += ft_putstr("(nil)");
			return (i);
		}
		else
			i = ft_putstr("0x");
	}
	if (nb > 15)
	{
		flag += 1;
		i += ft_putaddress(flag, nb / 16);
		i += ft_putchar(base[nb % 16]);
	}
	else
		i += ft_putchar(base[nb % 16]);
	return (i);
}
