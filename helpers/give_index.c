/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 19:01:49 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/16 19:58:33 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	give_index(t_list **stack_a)
{
	t_list	*temp;
	t_list	*temp2;
	int		i;

	temp = *stack_a;
	while (temp)
	{
		temp2 = *stack_a;
		i = get_index(&temp2, temp->content);
		temp->index = i;
		temp = temp->next;
	}
}
