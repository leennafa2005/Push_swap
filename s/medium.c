/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohal-al <mohal-al@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:47:37 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/15 18:29:56 by mohal-al         ###   ########.fr       */
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
}
void    give_chunk(t_list **stack_a)
{
    int     sizec;
    t_list *temp;
    
    temp = *stack_a;
    sizec = ft_sqrt(ft_lstsize(*stack_a));
    while (temp)
    {
        temp->chunk = (temp->index)/sizec;
        temp = temp->next;
    }
}
void    medium(t_list  **stack_a, t_list **stack_b)
{
    int j;
    int chunk_num;
    int chunk_size;
    int js;
    
    give_index(stack_a);
    give_chunk(stack_a);
    chunk_size = ft_sqrt(ft_lstsize(*stack_a));
    chunk_num = (ft_lstsize(*stack_a) / chunk_size) + 1;
    j = 0;
    while (*stack_a && j < chunk_num)
    {
        js = 0;
        while (*stack_a && js < chunk_size)
        {
            if ((*stack_a)->chunk == j)
            {
                pb(stack_a,stack_b);
                js ++;
            }
            else
                ra(stack_a); //jgrajkhgj
        }
        j ++;
    }
    print_stack(*stack_b, "b");
}
