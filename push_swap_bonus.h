/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:58:48 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/12 18:59:41 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line.h"
# include "push_swap.h"
# include <string.h>

void	sb_bonus(t_stack *first_node, t_stack *second_node);
void	sa_bonus(t_stack *first_node, t_stack *second_node);
void	rrb_bonus(t_stack **b);
void	rra_bonus(t_stack **a);
void	rb_bonus(t_stack **b);
void	ra_bonus(t_stack **a);
void	pb_bonus(t_stack **first_el, t_stack **b);
void	pa_bonus(t_stack **first_el, t_stack **a);
void	rrr(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	init_stack(int argc, char **argv, t_stack **a);
bool	check_error(int argc, char **argv);
int		check_digit(char **argv, int i, int j);
int		check_double(char **argv, int i, int j, int argc);

long	ft_atoi(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

void	stack_indexing(t_stack *a);
void	stack_moves(t_stack *a);
void	free_stack(t_stack **a);

int		count_word(const char *str, char c);

char	**allocate(const char *s, char c);
char	*alo_cpy(const char *s, int i, int j);
char	**free_all(char **p, int row);
char	**ft_split(char *s, char c);
int		split_args(char **argv, t_stack **a);

t_stack	*add_node_bonus(int content);
void	append_node(t_stack **head, t_stack *new_node);
#endif