/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ulti.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:14:35 by pzaw              #+#    #+#             */
/*   Updated: 2024/07/22 16:14:35 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		i += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putchar(nb % 10 + 48);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}

int	ft_putunbr(unsigned int nb)
{
	unsigned int	i;

	i = 0;
	if (nb > 9)
	{
		i += ft_putnbr(nb / 10);
		i += ft_putchar(nb % 10 + 48);
	}
	else
		i += ft_putchar(nb + 48);
	return (i);
}
