/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@learner.42.tech>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 01:50:14 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/10 09:15:49 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap2.h"
// parse the numbers if they are separated by spaces and store them in stack_a
int	parse_num(char *num, t_list **stack_a)
{
	char	**split_numbers;
	int		j;
	int		value;

	split_numbers = ft_split(num, ' ');
	if (!split_numbers)
		return (0);
	j = 0;
	while (split_numbers[j])
	{
		if (!ft_atoi(split_numbers[j], &value))
		{
			malloc_free(split_numbers);
			return (0);
		}
		if (!store_num(stack_a, value))
		{
			malloc_free(split_numbers);
			return (0);
		}
		j++;
	}
	malloc_free(split_numbers);
	return (1);
}
