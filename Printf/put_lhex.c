/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:13:07 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/10 17:13:07 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlhex(int fd, unsigned int n)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	if (n < 16)
		i = i + ft_putchar(fd, base[n]);
	else
	{
		i = i + ft_putlhex(fd, n / 16);
		i = i + ft_putlhex(fd, n % 16);
	}
	return (i);
}
