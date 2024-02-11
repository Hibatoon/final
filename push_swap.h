/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharra <hcharra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:59:16 by hcharra           #+#    #+#             */
/*   Updated: 2024/02/11 21:37:45 by hcharra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//#include <mcheck.h>

//#define END 2147483648

typedef struct s_list
{
	int				data;
	int				index;
	int				moves;

	struct s_list	*next;
}					t_stack;

void				init_stack(int argc, char **argv, t_stack **a);
bool				check_error(int argc, char **argv);
int					check_digit(char **argv, int i, int j);
int					check_double(char **argv, int i, int j, int argc);

t_stack				*add_node(int content);
void				append_node(t_stack **head, t_stack *new_node);
long				ft_atoi(const char *str);
int					list_size(t_stack *lst);
t_stack				*last_node(t_stack *lst);

void				stack_indexing(t_stack *a);
void				stack_moves(t_stack *a);
void				free_stack(t_stack **a);

void				tiny_sort(t_stack **a, t_stack **b, int argc);
char				**ft_split(char *s, char c);
int					split_args(char **argv, t_stack **a);

int					count_word(const char *str, char c);

void				pa(t_stack **first_el, t_stack **a);
void				pb(t_stack **first_el, t_stack **b);
void				ra(t_stack **a);
void				rra(t_stack **a);
void				swap_a(t_stack *first_node, t_stack *second_node);
void				swap_b(t_stack *first_node, t_stack *second_node);
void				rb(t_stack **b);
void				rrb(t_stack **b);

int					*init_arr(t_stack *a);
void				a_to_b(t_stack **a, t_stack **b);
void				b_to_a(t_stack **a, t_stack **b);
void				large_sort(t_stack **a, t_stack **b);

bool				is_sorted(t_stack *a);

void				fill_a(t_stack **a, t_stack **b);

void				quick_sort(int start, int end, int *arr);

int					max_moves(t_stack *b);

void				fill_it(t_stack **a, t_stack **b);

void				execute_actions(t_stack **a, t_stack **b);
void				both_actions(char *line, t_stack **a, t_stack **b);
void				b_actions(char *line, t_stack **a, t_stack **b);
void				a_actions(char *line, t_stack **a, t_stack **b);

void				fill_b(t_stack **a, t_stack **b);
void				neg_moves(int moves, t_stack **a);
void				pos_moves(int moves, t_stack **a);
int					large_helper(t_stack **a, int start, int end);
int					*sorted_arr(t_stack **x, int end);
void				a_to_b_help(int moves, t_stack **a, t_stack **b);
int					push_max(t_stack **b, t_stack **a, int end);
void				move_b(int moves, t_stack **b);
int					not_max(t_stack **b, t_stack **a, int index);
int					find_moves(int num, t_stack *b);
int					move_it(t_stack **a, t_stack **b, int end, int max);
// int					empty_bottom(t_stack **a, t_stack **b, int end);
bool				is_there(int num, t_stack *b);
void				full_bottom(t_stack **a, int index, int end);
int					return_end(t_stack **a, t_stack **b, int end);
void				still_there(t_stack **a, t_stack **b, int offset, int *arr);
void				index_and_move(t_stack **a);

typedef struct d_list
{
	int				*arr;
	int				size;
	int				offset;
	int				start;
	int				end;
	int				moves;
}					t_large;
int					get_offset(int size);
int					target_index(t_stack *a, int start, int end);
int					check_start(int start, int offset);
int					check_end(int end, int size, int offset);


typedef struct f_list
{
	int		*arr;
	int		end;
	t_stack	*temp;
	int		index;
}		t_fill;
void	ft_fill(t_stack **a, t_stack **b, t_fill fill_info);
t_fill	ft_assign(t_stack **a, t_stack **b);




//void    split_all(char **argv, t_stack **a);
int	split_all(int *argc, char **argv, t_stack **a);
bool	error_full_check(t_stack **a);

#endif