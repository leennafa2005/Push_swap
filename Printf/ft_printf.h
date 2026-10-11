/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 11:51:41 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/11 11:51:43 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putchar(int fd, char c);
int	ft_putstr(int fd, char *s);
int	ft_putdec(int fd, int n);
int	ft_putudec(int fd, unsigned int n);
int	ft_putlhex(int fd, unsigned int n);
int	ft_putuhex(int fd, unsigned int n);
int	ft_putptr(int fd, unsigned long n);
int	ft_put_float(int fd, double num);
int	ft_printf(int fd, const char *str, ...);

#endif
