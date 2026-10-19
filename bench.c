/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 18:44:33 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/19 14:06:06 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char *get_strategy(int s)
{
    if(s == 1)
        return("Adaptive /  OOOOOOOOOOOOOO");
    else if (s == 2)
        return("Simple / O(n^2)");
    else if (s ==3)
        return("Medium / O(n√n)");
    else if (s == 4)
        return("Complex / O(nlogn)");
    else
        return ("not a strategy");

}

void    bench(t_bench *bench_data, int strategy, float disoreder)
{

    ft_printf(2, "[bench] disorder:   %f%%\n", (double)disoreder * 100.0);
    ft_printf(2, "[bench] strategy:   %s\n",get_strategy(strategy));
    ft_printf(2, "[bench] total_ops:   %d\n", bench_data->total);
    ft_printf(2, "[bench] sa:  %d   sb:  %d   ss:  %d   pa:  %d   pb:  %d\n",
        bench_data->sa,bench_data->sb,bench_data->ss,bench_data->pa,bench_data->pb);
    ft_printf(2, "[bench] ra:  %d   rb:  %d   rr:  %d   rra:  %d   rrb:  %d   rrr:  %d\n",
        bench_data->ra,bench_data->rb,bench_data->rr,bench_data->rra,bench_data->rrb,bench_data->rrr);
}
