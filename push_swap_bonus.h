/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:58:48 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/05 21:58:49 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line.h"
# include "push_swap.h"
# include <string.h>

void	sb_bonus(stack *first_node, stack *second_node);
void	sa_bonus(stack *first_node, stack *second_node);
void	rrb_bonus(stack **b);
void	rra_bonus(stack **a);
void	rb_bonus(stack **b);
void	ra_bonus(stack **a);
void	pb_bonus(stack **first_el, stack **b);
void	pa_bonus(stack **first_el, stack **a);

void	init_stack(int argc, char **argv, stack **a);
bool	check_error(int argc, char **argv);
int		check_digit(char **argv, int i, int j);
int		check_double(char **argv, int i, int j, int argc);

long	ft_atoi(const char *str);

void	stack_indexing(stack *a);
void	stack_moves(stack *a);
void	free_stack(stack **a);

int		count_word(const char *str, char c);

char	**allocate(const char *s, char c);
char	*alo_cpy(const char *s, int i, int j);
char	**free_all(char **p, int row);
char	**ft_split(char *s, char c);
int		split_args(char **argv, stack **a);

stack	*add_node_bonus(int content);
void	append_node(stack **head, stack *new_node);
#endif