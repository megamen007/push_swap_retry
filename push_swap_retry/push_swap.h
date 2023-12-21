/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 10:02:48 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/20 18:51:12 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int			stack_size;
	int			counting_a;
	int			counting_b;
	int			*stack_a;
	int			*stack_b;
	int			top_a;
	int			top_b;
	int			max;
}				t_stack;

void			arguments_count(t_stack *stc, char **av);
int				*elements_filling(char **av, int stack_size);
int				duplicate_element(int *elements, int stack_size);
int				out_of_int_range(char **str, int i);
void			exit_(void);
long long int	ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
int				checking_is_already_sorted(t_stack *stack);
void			sorting_4(t_stack *stack);
void			sorting_3(t_stack *stack);
void			sorting_2(t_stack *stack);
void			sorting_algorithm(t_stack *stack);
void			ra(t_stack *stack);
void			rb(t_stack *stack);
void			rra(t_stack *stack);
void			rrb(t_stack *stack);
void			ss(t_stack *stack);
void			rrr(t_stack *stack);
void			rr(t_stack *stack);
void			sa(t_stack *stack);
void			sb(t_stack *stack);
void			sorting_5(t_stack *stack);
void			pb(t_stack *stack);
void			pa(t_stack *stack);
void			indexing_stack(t_stack *stack);
int				get_biggest_index(t_stack *stack, int biggest);
void			moving_biggest_element(t_stack *stack, int biggest);
void			sorting100_b_to_a(t_stack *stack);
void			sorting500_b_to_a(t_stack *stack);
void			sorting100_a_to_b(t_stack *stack);
void			sorting500_a_to_b(t_stack *stack);
int				extracting_max(t_stack *stack);
void			free_2d(char **str);
int				checking_is_already_backsorted(t_stack *stack);
void			sorting_backsorted_stack(t_stack *stack);
void			checking_errors(int *elements, int stack_size);
void			arguments_count(t_stack *stc, char **av);

#endif