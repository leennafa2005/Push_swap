/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohal-al <mohal-al@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 17:47:37 by lnafa             #+#    #+#             */
/*   Updated: 2026/10/15 20:01:45 by mohal-al         ###   ########.fr       */
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

static int	get_steps(t_list *b, int val)
{
	int	steps;

	steps = 0;
	while (b && val != b->chunk)
	{
		steps++;
		b = b->next;
	}
	return (steps);
}


void    medium2(t_list  **stack_a, t_list **stack_b , int chunk_size, int chunk_num)
{
    int j;
    int js;
    
    j = 0;
    while (*stack_a && j < chunk_num)
    {
        js = 0;
        while (*stack_a && js < (chunk_size))
        {
            if ((*stack_a)->chunk == j)
            {
                pb(stack_a,stack_b);
                js ++;
            }
            else if(get_steps(*stack_a, j) <= (ft_lstsize(*stack_a)/ 2) )
                ra(stack_a);
            else
                rra(stack_a);
        }
        j ++;
    }
}
static int	get_steps2(t_list *b, int val)
{
	int	steps;

	steps = 0;
	while (b && val != b->index)
	{
		steps++;
		b = b->next;
	}
	return (steps);
}
int    get_max(t_list **stack_b)
{
    int max;
    t_list *temp;

    temp = *stack_b;
    max = (*stack_b) -> index;
    while (temp)
    {
        if(max < temp -> index)
            max = temp->index;
        temp = temp->next;
    }
    return (max);
    //print_stack(*stack_b, "b");
}
void    medium(t_list **stack_a,t_list **stack_b)
{
    int chunk_num;
    int chunk_size;
    int size_b;
    int steps;
    
    give_index(stack_a);
    give_chunk(stack_a);
    chunk_size = ft_sqrt(ft_lstsize(*stack_a));
    chunk_num = (ft_lstsize(*stack_a) / chunk_size) + 1;
    medium2(stack_a, stack_b, chunk_size, chunk_num);
    while (*stack_b)
    {
         size_b = ft_lstsize(*stack_b);
		steps = get_steps2(*stack_b, get_max(stack_b));
		if (steps != 0 && steps <= size_b / 2)
			while (steps--)
				rb(stack_b);
		else
			while (steps != 0 && steps++ < size_b)
				rrb(stack_b);
		pa(stack_a,stack_b);
	}
   // print_stack(*stack_a, "a");
}
