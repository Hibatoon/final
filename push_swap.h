#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

//#include <mcheck.h>

//#define END 2147483648

typedef struct s_list
{
    int data;
    int index;
    int moves;

    struct s_list *next;
} stack;

void    init_stack(int argc, char **argv, stack **a);
bool    check_error(int argc, char **argv);
int     check_digit(char **argv, int i, int j);
int    check_double(char **argv, int i, int j, int argc);

stack *add_node(int content);
void append_node(stack **head, stack *new_node);
long	ft_atoi(const char *str);
int	list_size(stack *lst);
stack	*last_node(stack *lst);

void    stack_indexing(stack *a);
void    stack_moves(stack *a);
void    free_stack(stack **a);

void    tiny_sort(stack **a, stack **b, int argc);
char	**ft_split(char *s, char c);
int	split_args(char **argv, stack **a);

int	count_word(const char *str, char c);

void    pa(stack **first_el, stack **a);
void    pb(stack **first_el, stack **b) ;
void    ra(stack **a);
void    rra(stack **a);
void    swap_a(stack *first_node, stack *second_node);
void    swap_b(stack *first_node, stack *second_node);
void    rb(stack **b);
void    rrb(stack **b);


int *init_arr(stack *a);
void    a_to_b(stack **a, stack **b);
void    b_to_a(stack **a, stack **b);
void    large_sort(stack **a, stack **b);

bool is_sorted(stack *a);

void    fill_a(stack **a, stack **b);

void    quick_sort(int start, int end, int *arr);

int     max_moves(stack *b);

void    fill_it(stack **a, stack **b);


void    execute_actions(stack **a, stack **b);
void    both_actions(char *line, stack **a, stack **b);
void    b_actions(char *line, stack **a, stack **b);
void    a_actions(char *line, stack **a, stack **b);


stack *helper(stack **b);
void    sort_list(stack **c, stack **b);
void    totoro(stack **a, stack **b);
stack* mergeSort(stack* head);
#endif