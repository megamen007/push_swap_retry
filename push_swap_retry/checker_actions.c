/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:42:17 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/24 23:46:48 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void ss(t_stack *stc)
{
    sa(stc);
    sb(stc);
}

void rrr(t_stack *stc)
{
    rra(stc);
    rrb(stc);
}

void rr(t_stack *stc)
{
    ra(stc);
    rb(stc);
}

void sa(t_stack *stc)
{
    int i;
    int data;

    i = stc->top_a;
    data = stc->stack_a[i];
    stc->stack_a[i] = stc->stack_a[i - 1];
    stc->stack_a[i - 1] = data;

}

void sb(t_stack *stc)
{
    int i;
    int data;

    i = stc->top_b;
    data = stc->stack_b[i];
    stc->stack_b[i] = stc->stack_b[i - 1];
    stc->stack_b[i - 1] = data;

}

void ra(t_stack *stc)
{
    int i;
    int data;

    i = stc->top_a;
    data = stc->stack_a[stc->top_a];
    while (i > 0)
    {
        stc->stack_a[i] = stc->stack_a[i - 1];
        i--;
    }
    stc->stack_a[i] = data;

}

void rb(t_stack *stc)
{
    int i;
    int data;

    i = stc->top_b;
    data = stc->stack_b[stc->top_b];
    while (i > 0)
    {
        stc->stack_b[i] = stc->stack_b[i - 1];
        i--;
    }
    stc->stack_b[i] = data;

}

void rra(t_stack *stc)
{
    int i;
    int data;

    i = 0;
    data = stc->stack_a[0];
    while(i <= stc->top_a)
    {
        stc->stack_a[i - 1] = stc->stack_a[i];
        i++;
    }
    stc->stack_a[stc->top_a] = data;

}

void rrb(t_stack *stc)
{
    int i;
    int data;

    i = 0;
    data = stc->stack_b[0];
    while(i <= stc->top_b)
    {
        stc->stack_b[i - 1] = stc->stack_b[i];
        i++;
    }
    stc->stack_b[stc->top_b] = data;

}

void pa(t_stack *stc)
{
    stc->top_a++;
    stc->stack_a[stc->top_a] = stc->stack_b[stc->top_b];
    stc->stack_b[stc->top_b] = 0;
    stc->top_b--;
    stc->count_a++;
    stc->count_b--;
}

void pb(t_stack *stc)
{
    stc->top_b++;
    stc->stack_b[stc->top_b] = stc->stack_a[stc->top_a];
    stc->stack_a[stc->top_a] = 0;
    stc->top_a--;
    stc->count_a--;
    stc->count_b++;
}