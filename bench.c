/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 18:44:33 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/19 16:49:21 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*get_strategy(int s, float d)
{
	if (s == ADAPTIVE)
	{
		if (d < 0.2)
			return ("Adaptive / O(n^2)");
		else if (d >= 0.2 && d < 0.5)
			return ("Adaptive / O(n√n)");
		else if (d >= 0.5)
			return ("Adaptive / O(nlogn)");
	}
	else if (s == SIMPLE)
		return ("Simple / O(n^2)");
	else if (s == MEDIUM)
		return ("Medium / O(n√n)");
	else if (s == COMPLEX)
		return ("Complex / O(nlogn)");
	return ("not a strategy");
}

void	bench(t_bench *bench_data, int strategy, float disoreder)
{
	ft_printf(2, "[bench] disorder:   %f%%\n", (double)disoreder * 100.0);
	ft_printf(2, "[bench] strategy:   %s\n", get_strategy(strategy, disoreder));
	ft_printf(2, "[bench] total_ops:   %d\n", bench_data->total);
	ft_printf(2, "[bench] sa:  %d   sb:  %d   ss:  %d   pa:  %d   pb:  %d\n",
		bench_data->sa, bench_data->sb, bench_data->ss, bench_data->pa,
		bench_data->pb);
	ft_printf(2, "[bench] ra:  %d   rb:  %d   rr:  %d   ", bench_data->ra,
		bench_data->rb, bench_data->rr);
	ft_printf(2, "rra:  %d   rrb: %d   rrr:  %d\n", bench_data->rra,
		bench_data->rrb, bench_data->rrr);
}
