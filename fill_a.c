#include "push_swap.h"

// void    fill_a(stack **a, stack **b)
// {
//     int *arr = init_arr(*a);
//     int end = list_size(*b) - 1;  //15

//     quick_sort(0, end, arr);

//     int mmoves = max_moves(*b); //1

//     if(mmoves > 0)
//     {
//         while(moves --)
//             rb(b);
//     }
//     else if (mmoves < 0)
//     {
//         while(mmoves++)
//             rrb(b);
//     }
//     pa(b, a);
//     pa(b, a);
//     ra(a);

//     while(list_size(*b))
//     {
//         end = list_size(*b) - 1;
//         int max = arr[end];
//         stack *temp = *b;
//         int moves = INT_MAX;
//         stack_moves(*b);

//         while(temp)
//         {
//             if(temp -> data == max)
//                 moves = temp -> moves;
//             temp = temp -> next;
//         }
        
//         if(moves = INT_MAX)
//             rra(a);
//         else if(moves > 0)
//         {
//             while(moves--)
//                 rb(b);
//             pa(b, a);
//         }
//         else if(moves < 0)
//         {
//             while(moves++)
//                 rrb(b);
//             pa(b, a);
//         }
//         else
//             pa(b, a);
//     }
// }




// void    fill_a(stack **a, stack **b)
// {
//     ///printf("filling a\n");
//     int *arr = init_arr(*b);
//     int end = list_size(*b) - 1;

//     quick_sort(0, end, arr);
//     stack_moves(*b);
//     int mmoves = max_moves(*b);

//     ///printf("max moves : %d\n", mmoves);
    
//     if(mmoves < 0)
//     {
//         while(mmoves++)
//             rrb(b);
//     }
//     else if (mmoves > 0)
//     {
//         while(mmoves--)
//             rb(b);
//     }
//     pa(b, a);

//     int index = 0;

//     while(list_size(*b))
//     {
//         ///printf("--> loop\n");
//         ///printf("--> index : %d\n", index);
//         int end = list_size(*b) - 1;
//         stack *temp = *b;
//         ///printf("--> target : %d\n", arr[end]);
//         if(temp -> data == arr[end])
//             pa(b, a);
//         else if(temp -> data != arr[end] && index == 0)
//         {
//             pa(b, a);
//             rra(a);
//             index = 1;
//         }
//         end--;
//         if(index)
//         {
//             stack *tmp = *b;
//             int moves = INT_MAX;
//             stack_moves(*b);

//             while(tmp)
//             {
//                 if(tmp -> data == arr[end])
//                     moves = tmp -> moves;
//                 tmp = tmp -> next;
//             }
//             ///printf("moves : %d\n", moves);
            
//             if(moves == INT_MAX && index)
//             {
//                 rra(a);
//                 //end--;
//                 index = 0;
//             }
//             else if(moves > 0)
//             {
//                 while(moves--)
//                     rb(b);
//                 pa(b, a);
//             }
//             else if(moves < 0)
//             {
//                 while(moves++)
//                     rrb(b);
//                 pa(b, a);
//             }
//         }
//         // else
//         //     pa(b, a);
//     }
// }

// void find_best_move()
// {

// }
// void fill_a(stack **a , stack **b)
// {
//    int *arr = init_arr(*b);
//    int end = list_size(*b) - 1;
//    int i ;

//   quick_sort(0, end, arr);

//   push_a(b,a);
//   end--;
//   m = 0;
//   while()
//   {
//     if(m == 0)
//     {
//         push_a()
//         rra()
//         i
//         m = 1;
//     }
//     else if(m == 1)
//     {
//         max= ar[end]
//         push_a;
//         end --;
//     }
//     if()
//     {
//     arr[end] == last()
//     m = 0;
//     }
//   }

// }

bool    there_is(stack *b, int value);

void    fill_a(stack **a, stack **b)
{
    ///printf("Entered\n");
    int *arr = init_arr(*b);
    int end = list_size(*b) - 1;

    quick_sort(0, end, arr);
    stack_moves(*b);
    stack *temp = *b;
    int moves = 0;
    while(temp -> next && temp)
    {
        if(temp -> data == arr[end])
            moves = temp -> moves;
        /////printf("data : %d arr[end] : %d\n", temp -> data, arr[end]);
        temp = temp -> next;
    }
    ///printf("moves : %d\n", moves);
    if(moves > 0)
    {
        while(moves--)
            rb(b);
        //printf("SEGV\n");
    }
    else if (moves < 0)
    {
        while(moves++)
            rrb(b);
    }
    pa(b, a);
    end--;
    int index = 0;
    temp = *b;
    while(temp)
    {
        printf("--> %d\n", temp -> data);
        temp = temp -> next;
    }
    while(end >= 0)
    {
        printf("ENTERING THE LOOP\n");
        stack_moves(*b);
        //end = list_size(*b);
        temp = *b;
        printf("arr[end] : %d\n", arr[end]);
        if(temp -> data == arr[end])
        {
            pa(b, a);
            end--;
            continue;
        }
        else if(temp -> data != arr[end] && index == 0)
        {
            ///printf("we are changing the index\n");
            pa(b, a);
            ra(a);
            index = 1;
            continue;
        }
        printf("little check arr[end] : %d\n", arr[end]);
        if(there_is(*b, arr[end]))
        {
            stack_moves(*b);
            printf("data")
            temp = *b;
            while(temp -> next && temp)
            {
                if(temp -> data == arr[end])
                    moves = temp -> moves;
                temp = temp -> next;
            }
            ///printf("first element : %d\n", (*b) -> data);
            ///printf("array end : %d\n", arr[end]);
            printf("second moves: %d\n", moves);
            if(moves > 0)
            {
                while(moves--)
                    rb(b);
            }
            else if (moves < 0)
            {
                while(moves++)
                    rrb(b);
            }
            pa(b, a);
            end--;
        }
        else
        {
            rra(a);
            index = 0;
            end--;
        }
        printf("arr index : %d arr value : %d\n", end, arr[end]);
    }
    free(arr);
}

bool     there_is(stack *b, int value)
{
    stack *temp = b;

    while(temp)
    {
        if(temp -> data == value)
            return(true);
        temp = temp -> next;
    }
    return(false);
}