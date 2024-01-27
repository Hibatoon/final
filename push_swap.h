#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

//#define END 2147483648

typedef struct s_list
{
    int data;
    int index;
    int moves;

    struct s_list *next;
} stack;

void    init_stack(int argc, char **argv, stack **a);
stack *add_node(int content);
void append_node(stack **head, stack *new_node);
long	ft_atoi(const char *str);
int	list_size(stack *lst);
void    stack_indexing(stack *a);
void    stack_moves(stack *a);
void    tiny_sort(stack **a, stack **b, int argc);
char	**ft_split(const char *s, char c);

void    pa(stack **first_el, stack **a);
void    pb(stack **first_el, stack **b) ;
void    ra(stack **a);
void    rra(stack **a);
void    swap_a(stack *first_node, stack *second_node);
void    rb(stack **b);
void    rrb(stack **b);


int *init_arr(stack *a);
void    a_to_b(stack **a, stack **b);
void    b_to_a(stack **a, stack **b);
#endif