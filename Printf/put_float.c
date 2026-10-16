/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_float.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 04:59:48 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/16 19:35:32 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_float(int fd, double num)
{
	int	integer;
	int	decimal;
	int	i;

	i = 0;
	if (num < 0)
	{
		i += write(fd, "-", 1);
		num = -num;
	}
	integer = num;
	decimal = ((num - integer) * 100 + 0.5);
	if (decimal == 100)
	{
		integer++;
		decimal = 0;
	}
	i += ft_putdec(fd, integer);
	i += write(fd, ".", 1);
	if (decimal < 10)
		i += write(fd, "0", 1);
	i += ft_putdec(fd, decimal);
	return (i);
}
