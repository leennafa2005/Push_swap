/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 07:21:52 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/22 17:59:21 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_overflow(long result, int sign, char c)
{
	if (sign == 1 && result > (2147483647 - (c - '0')) / 10)
		return (0);
	if (sign == -1 && result > (-(long)-2147483648 - (c - '0')) / 10)
		return (0);
	return (1);
}

int	ft_atoi(const char *num, int *value)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*num == ' ' || (*num >= 9 && *num <= 13))
		num++;
	if (*num == '+' || *num == '-')
	{
		if (*num == '-')
			sign = -1;
		num++;
	}
	if (!is_digit(num))
		return (0);
	while (*num >= '0' && *num <= '9')
	{
		if (!check_overflow(result, sign, *num))
			return (0);
		result = result * 10 + (*num - '0');
		num++;
	}
	*value = (int)(result * sign);
	return (1);
}
