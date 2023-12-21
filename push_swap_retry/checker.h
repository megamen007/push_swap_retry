/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboudrio <mboudrio@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:48:46 by mboudrio          #+#    #+#             */
/*   Updated: 2023/12/21 18:18:34 by mboudrio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			count_a;
	int			count_b;
	int			top_a;
	int			top_b;
	int			size;
}				t_stack;

int				duplicate_element(int *elements, t_stack *stc);
void			checking_errors(int *element, t_stack *stc);
void			pa(t_stack *stc);
void			pb(t_stack *stc);
void			sa(t_stack *stc);
void			ss(t_stack *stc);
void			sb(t_stack *stc);
void			rrr(t_stack *stc);
void			rr(t_stack *stc);
void			ra(t_stack *stc);
void			rb(t_stack *stc);
void			rra(t_stack *stc);
void			rrb(t_stack *stc);
void			checking_arg(char *str, t_stack *stc);
void			checker_core(t_stack *stc);
void			checker(t_stack *stc);
int				checking_if_sorted(t_stack *stc);
void			filling_stack(t_stack *stc, int *element);
void			exit_(void);
void			arguments_count(t_stack *stc, char **av);
int				*fill_elements(char **av, t_stack *stc);
char			*getting_line(int fd);
int				ft_strlen(char *str);
int				ft_strcmp(char *s1, char *s2);
char			**ft_split(char const *s, char c);
long long int	ft_atoi(const char *str);
void			free_2d(char **str);

#endif