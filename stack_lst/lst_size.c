/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohal-al <mohal-al@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:02:04 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/08 20:04:03 by mohal-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i ++;
	}
	return (i);
}
