/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnafa <lnafa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:47:37 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/14 20:36:59 by lnafa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int     get_index(t_list    **stack_a, int value)
{
    t_list *temp;
    int     count;

    temp = *stack_a;
    count = 0;
    while(temp)
    {
        if (temp -> content < value)
            count ++;
        temp = temp->next;
    }
    return (count);
}

void    give_index(t_list **stack_a)
{
    t_list *temp;
    t_list  *temp2;
    int i;

    temp = *stack_a;
    while (temp)
    {
        temp2 = *stack_a; 
        i = get_index(&temp2, temp->content);
        temp -> index = i;
        temp = temp -> next;
    }
    /*
    while (*stack_a)
    {
        //i = get_index(&temp, temp->content);
       printf("%d\n",  (*stack_a) -> index);
        (*stack_a) = (*stack_a) -> next;
    }
    */
}
void    give_chunk(t_list **stack_a)
{
    int     sizec;
    t_list *temp;
    
    temp = *stack_a;
    sizec = sqrt(ft_lstsize(*stack_a));
    while (temp)
    {
        temp->chunk = (temp->index)/sizec;
        temp = temp->next;
    }
}
/*void    medium(t_list  **stack_a, t_list **stack_b)
{
    int 
}*/