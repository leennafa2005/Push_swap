/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohal-al <mohal-al@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 20:06:27 by mohal-al          #+#    #+#             */
/*   Updated: 2026/10/08 20:07:35 by mohal-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*nextlst;

	if (!lst || !*lst || !del)
		return ;
	temp = *lst;
	while (temp != NULL)
	{
		nextlst = temp->next;
		ft_lstdelone(temp, del);
		temp = nextlst;
	}
	*lst = NULL;
}
