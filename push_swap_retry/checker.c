/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:46:37 by mboudrio          #+#    #+#             */
/*   Updated: 2023/11/25 16:04:06 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void exit_()
{
    write(1,"ERROR\n", 6);
    exit(1);
}

int *fill_elements(char **av, t_stack *stc)
{
    int i;
    int j;
    int k;
    char **str;
    int *element;
    
    element = malloc(sizeof(int) * stc->size);
    i = 1;
    j = 0;
    while (av[i])
    {
        str = ft_split(av[i], ' ');
        k = 0;
        while (str[k])
        {
            if (ft_atoi(str[k]) > INT_MAX || ft_atoi(str[k]) < INT_MIN)
               exit_();
            element[j] = ft_atoi(str[k]);
            j++;
            k++;
        }
        i++;
    }
    return element; 
}
int duplicate_element(int *elements, t_stack *stc)
{
    int i;
    int j;

    i = 0;
    while(i < stc->size)
    {
        j = i + 1;
        while (j < stc->size)
        {
            if (elements[i] == elements[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void checking_errors(int *element, t_stack *stc)
{
    if (duplicate_element(element, stc) == 0)
        exit_();
}
void filling_stack(t_stack *stc, int *element)
{
    int i;
    int j;

    i = 0;
    j = stc->size - 1;
    stc->top_a = -1;
    stc->top_b = -1;
    stc->stack_a = malloc(sizeof(int) * stc->size);
    stc->stack_b = malloc(sizeof(int) * stc->size);
    while (i < stc->size)
    {
        stc->stack_a[i] = element[j];
        i++;
        j--;
        stc->top_a++; 
    }     
}

int  checking_if_sorted(t_stack *stc)
{
    int i;

    i = 0;
    while (i < stc->size - 1)
    {
        if (stc->stack_a[i] > stc->stack_a[i + 1])
            i++;
        else
            return (1);
    }
    return (0);
}

void checking_arg(char *str, t_stack *stc)
{
    if (ft_strcmp(str, "sa\n") == 0)
		sa(stc);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stc);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stc);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(stc);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stc);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stc);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stc);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stc);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stc);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stc);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stc);
    else 
        return;
}
void    checker_core(t_stack *stc)
{
    if (checking_if_sorted(stc) == 0 && stc->stack_a[stc->top_b] == 0)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
}
void checker(t_stack *stc)
{
    char *str;
    
    str = get_next_line(0);
    while(str)
    {
        checking_arg(str, stc);
        str = get_next_line(0);
    }
    checker_core(stc);
}

void	print_stack(t_stack *stacks)
{
	int	i;

	i = stacks->size - 1;
	while (i >= 0)
	{
		printf("A-->%i\n", stacks->stack_a[i]);
		i--;
	}
}

int main (int ac , char **av)
{
    t_stack *stc;
    int *element;

    stc = malloc(sizeof(t_stack));
    stc->size = ac - 1;
    element = fill_elements(av, stc);
    checking_errors(element, stc);
    filling_stack(stc, element);
    if (checking_if_sorted(stc) == 0)
        {
            write(1,"-->stack already sorted\n",24);
            exit(0);
        }
    else 
        {
          checker(stc);
        }
}