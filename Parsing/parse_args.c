/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 04:18:44 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/11 18:21:49 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// the main function to parse the arguments and store the numbers in stack_a
int	parse_args(int ac, char **av, t_flag *flag, t_list **stack_a)
{
	int	i;

	init_flags(flag);
	i = 1;
	while (i < ac)
	{
		if (ft_strncmp(av[i], "--", 2) == 0)
		{
			if (!parse_flags(av[i], flag))
				return (write(2, "Error\n", 6), 0);
		}
		else
		{
			if (!parse_num(av[i], stack_a))
				return (write(2, "Error\n", 6), 0);
		}
		i++;
	}
	return (1);
}
