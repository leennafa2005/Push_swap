/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:10:39 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/10 17:10:39 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putudec(int fd, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n <= 9)
		i = i + ft_putchar(fd, n + '0');
	else
	{
		i = i + ft_putudec(fd, n / 10);
		i = i + ft_putudec(fd, n % 10);
	}
	return (i);
}
