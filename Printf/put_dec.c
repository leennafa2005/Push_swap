/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:19:07 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/10 17:19:07 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdec(int fd, int n)
{
	int		i;
	long	nb;

	i = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		i = i + write(fd, "-", 1);
	}
	if (nb >= 0 && nb <= 9)
		i = i + ft_putchar(fd, nb + '0');
	if (nb >= 10)
	{
		i = i + ft_putdec(fd, nb / 10);
		i = i + ft_putdec(fd, nb % 10);
	}
	return (i);
}
