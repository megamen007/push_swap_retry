/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:55:47 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/03 08:17:16 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	checking_if_sorted(t_stack *stc)
{
	int	i;

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

void	checking_arg(char *str, t_stack *stc)
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
		exit_();
}

void	checker_core(t_stack *stc)
{
	if (checking_if_sorted(stc) == 0 && stc->top_b == -1)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

void	checker(t_stack *stc)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		checking_arg(str, stc);
        free(str);
		str = get_next_line(0);
	}
	checker_core(stc);
    
}

void	checking_errors(int *element, t_stack *stc)
{
	if (duplicate_element(element, stc) == 0)
		exit_();
}
