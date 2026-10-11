/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 01:50:14 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/11 18:22:07 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	free_split(char **split_numbers)
{
	if (split_numbers)
		malloc_free(split_numbers);
	return (0);
}

int	parse_num(char *num, t_list **stack_a)
{
	char	**split_numbers;
	int		j;
	int		value;

	split_numbers = ft_split(num, ' ');
	if (!split_numbers || !split_numbers[0])
		return (free_split(split_numbers));
	j = 0;
	while (split_numbers[j])
	{
		if (!ft_atoi(split_numbers[j], &value))
			return (free_split(split_numbers));
		if (!store_num(stack_a, value))
			return (free_split(split_numbers));
		j++;
	}
	malloc_free(split_numbers);
	return (1);
}
