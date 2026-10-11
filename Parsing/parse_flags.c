/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 14:36:39 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/11 18:21:59 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_strategy(char *arg)
{
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (ADAPTIVE);
	else if (ft_strcmp(arg, "--simple") == 0)
		return (SIMPLE);
	else if (ft_strcmp(arg, "--medium") == 0)
		return (MEDIUM);
	else if (ft_strcmp(arg, "--complex") == 0)
		return (COMPLEX);
	return (INVALID);
}

int	is_bench(char *arg)
{
	if (ft_strcmp(arg, "--bench") == 0)
		return (1);
	return (0);
}
// initialize the flags structure with default values

void	init_flags(t_flag *flag)
{
	flag->strategy = ADAPTIVE;
	flag->bench = 0;
	flag->strategy_set = 0;
	flag->bench_set = 0;
}

int	parse_flags(char *arg, t_flag *flag)
{
	int	strategy;

	strategy = is_strategy(arg);
	if (strategy != INVALID)
	{
		if (flag->strategy_set)
			return (0);
		flag->strategy = strategy;
		flag->strategy_set = 1;
		return (1);
	}
	if (is_bench(arg))
	{
		if (flag->bench_set)
			return (0);
		flag->bench = 1;
		flag->bench_set = 1;
		return (1);
	}
	return (0);
} 
