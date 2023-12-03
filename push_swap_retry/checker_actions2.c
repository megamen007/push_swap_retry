/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 04:51:35 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/03 08:22:43 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	pa(t_stack *stc)
{
	if (stc->top_b > -1)
	{
		stc->top_a++;
		stc->stack_a[stc->top_a] = stc->stack_b[stc->top_b];
		stc->top_b--;
		stc->count_a++;
		stc->count_b--;
	}
	else
		return ;
}

void	pb(t_stack *stc)
{
	if (stc->top_a > -1)
	{
		stc->top_b++;
		stc->stack_b[stc->top_b] = stc->stack_a[stc->top_a];
		stc->top_a--;
		stc->count_a--;
		stc->count_b++;
	}
	else
		return ;
}

void	exit_(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
