#include "push_swap.h"


void    move_b(int moves, stack **b)
{
    if(moves > 0)
    {
        while(moves--)
            rb(b);
    }
    else if(moves < 0)
    {
        while(moves++)
            rrb(b);
    }
}

bool is_there(int num, stack *b)
{
    //stack_moves(b);
    stack *temp = b;
    //static int actions = 0;

    while(temp)
    {
        if(temp -> data == num)
        {
            //actions = temp -> moves;
            return true;
        }
        temp = temp -> next;
    }
    return false;
}

int     find_moves(int num, stack *b)
{
    stack_moves(b);
    stack *temp = b;

    while(temp)
    {
        if(temp -> data == num)
            return(temp -> moves);
        temp = temp -> next;
    }
    return 0;
}
void    fill_it(stack **a, stack **b)
{
    int *arr = init_arr(*b);
    int end = list_size(*b) - 1;
    int moves = 0;

    quick_sort(0, end, arr);

    stack_moves(*b);



    
    stack *temp = *b;
    
    while(temp)
    {
        if(temp -> data == arr[end])
            moves = temp -> moves;
        temp = temp -> next;
    }
    
    
    move_b(moves, b);
    pa(b, a);
    end--;
    printf("NEW ENNNNND : %d\n", end);
    int index = 0;

    while(list_size(*b))
    {
        printf("list size : %d\n", list_size(*b));
        stack_moves(*b);
        temp = *b;
        //end = list_size(*b) - 1;

        stack *lol = *b;

        while(lol)
        {
            printf("--> %d\n", lol -> data);
            lol = lol -> next;
        }
        // int i = 0;

        // while(i < list_size(*b))
        // {
        //     printf("arr[%d] : %d\n", i, arr[i]);
        //     i++;
        // }
        printf("max pos in arr : %d\n", end);
        printf("new max : %d\n", arr[end]);

        if(temp -> data == arr[end] && index == 0)
        {
            pa(b, a);
            end--;
        }
        else if(temp -> data != arr[end] && index == 0)
        {
            pa(b, a);
            ra(a);
            index = 1;
        }

        if(index == 1)
        {
            if(is_there(arr[end], *b))
            {
                moves = find_moves(arr[end], *b);

                printf("moves : %d\n", moves);

                move_b(moves, b);
                pa(b, a);
                end--;
            }
            else
            {
                rra(a);
                end--;
                index = 0;
            }
        }
    }

}

int main()
{
    stack *a = NULL;
    stack *b = add_node(11);

    append_node(&b, add_node(25));
    append_node(&b, add_node(10));
    append_node(&b, add_node(32));
    append_node(&b, add_node(4));
    append_node(&b, add_node(22));
    append_node(&b, add_node(6));
    append_node(&b, add_node(9));
    append_node(&b, add_node(15));
    append_node(&b, add_node(8));
    append_node(&b, add_node(17));
    append_node(&b, add_node(5));
    append_node(&b, add_node(1));
    append_node(&b, add_node(0));
    append_node(&b, add_node(2));
    append_node(&b, add_node(3));
    append_node(&b, add_node(-8));
    append_node(&b, add_node(-10));
    append_node(&b, add_node(-6));
    append_node(&b, add_node(-4));
    append_node(&b, add_node(-2));
    append_node(&b, add_node(-1));

     stack *temp = b;

    // while(temp)
    // {
    //     printf("%d\n", temp -> data);
    //     temp = temp -> next;
    // }

    fill_it(&a, &b);

    temp = a;
    while(temp)
    {
        printf("%d\n", temp -> data);
        temp = temp -> next;
    }

    // int *arr = init_arr(b);
    // quick_sort(0, list_size(b) - 1, arr);
    // int i = 0;

    // while(i < list_size(b))
    // {
    //     printf("arr[%d] : %d\n", i, arr[i]);
    //     i++;
    // }
}