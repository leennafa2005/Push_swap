/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:15:03 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/10 17:15:03 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putuhex(int fd, unsigned int n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	if (n < 16)
		i = i + ft_putchar(fd, base[n]);
	else
	{
		i = i + ft_putuhex(fd, n / 16);
		i = i + ft_putuhex(fd, n % 16);
	}
	return (i);
}
