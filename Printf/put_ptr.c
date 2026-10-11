/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:12:05 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/10 17:12:05 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putaddr(int fd, unsigned long n)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (n < 16)
		i = i + ft_putchar(fd, base[n]);
	else
	{
		i = i + putaddr(fd, n / 16);
		i = i + putaddr(fd, n % 16);
	}
	return (i);
}

int	ft_putptr(int fd, unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (write(fd, "(nil)", 5));
	i = i + write(fd, "0x", 2);
	i = i + putaddr(fd, n);
	return (i);
}
