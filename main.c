/*
#include "push_swap.h"
#include <stdio.h>

void p_s(t_list *a, t_list *b)
{
    printf("A: ");
    while (a)
    {
        printf("%d ", a->content);
        a = a->next;
    }
    printf("\nB: ");
    while (b)
    {
        printf("%d ", b->content);
        b = b->next;
    }
    printf("\n----------------\n");
}

int main(void)
{
    t_list *a = NULL;
    t_list *b = NULL;

    ft_lstadd_front(&a, ft_lstnew(1));
    ft_lstadd_front(&a, ft_lstnew(2));
    ft_lstadd_front(&a, ft_lstnew(3));

    ft_lstadd_front(&b, ft_lstnew(4));
    ft_lstadd_front(&b, ft_lstnew(5));
    ft_lstadd_front(&b, ft_lstnew(6));

    printf("INIT:\n");
    p_s(a, b);

    printf("sa & sb:\n");
    sa(&a);
    sb(&b);
    p_s(a, b);

    printf("ss:\n");
    ss(&a, &b);
    p_s(a, b);

    printf("pb x2:\n");
    pb(&a, &b);
    pb(&a, &b);
    p_s(a, b);

    printf("pa:\n");
    pa(&a, &b);
    p_s(a, b);

    printf("ra & rb:\n");
    ra(&a);
    rb(&b);
    p_s(a, b);

    printf("rr:\n");
    rr(&a, &b);
    p_s(a, b);

    printf("rra & rrb:\n");
    rra(&a);
    rrb(&b);
    p_s(a, b);

    printf("rrr:\n");
    rrr(&a, &b);
    p_s(a, b);

    return (0);
}
*/