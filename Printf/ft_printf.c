/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 17:20:15 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/18 19:49:44 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(int fd, va_list arg, char c)
{
	int	n;

	n = 0;
	if (c == 'd' || c == 'i')
		n = ft_putdec(fd, va_arg(arg, int));
	else if (c == 'u')
		n = ft_putudec(fd, va_arg(arg, unsigned int));
	else if (c == 'c')
		n = ft_putchar(fd, va_arg(arg, int));
	else if (c == 's')
		n = ft_putstr(fd, va_arg(arg, char *));
	else if (c == 'x')
		n = ft_putlhex(fd, va_arg(arg, unsigned int));
	else if (c == 'X')
		n = ft_putuhex(fd, va_arg(arg, unsigned int));
	else if (c == 'p')
		n = ft_putptr(fd, (unsigned long)va_arg(arg, void *));
	else if (c == 'c')
		n = ft_put_float(fd, va_arg(arg, double));
	else if (c == '%')
		return (ft_putchar(fd, '%'));
	return (n);
}

int	ft_printf(int fd, const char *str, ...)
{
	int		i;
	int		n;
	va_list	arg_list;

	i = 0;
	n = 0;
	va_start(arg_list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			n = n + check_format(fd, arg_list, str[i]);
		}
		else
			n = n + ft_putchar(fd, str[i]);
		i++;
	}
	va_end(arg_list);
	return (n);
}
