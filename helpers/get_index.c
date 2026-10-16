/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 19:50:51 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/16 19:59:10 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(t_list **stack_a, int value)
{
	t_list	*temp;
	int		count;

	temp = *stack_a;
	count = 0;
	while (temp)
	{
		if (temp->content < value)
			count++;
		temp = temp->next;
	}
	return (count);
}
