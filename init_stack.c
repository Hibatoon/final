#include "push_swap.h"


static int    check_double(char **argv, int i, int j, int argc)
{
    while(j < argc)
    {
        if(ft_atoi(argv[i]) == ft_atoi(argv[j]))
        {
            write(2, "Error\n", 6);
            return 1;
        }
        j++;
    }
    return 0;
}

static int     check_digit(char **argv, int i, int j)
{
    while(argv[i][j])
    {
        if(!(((argv[i][j] >= '0'  && argv[i][j] <= '9') || ((j == 0 && argv[i][j] == '-') && (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')))))
        {
            write(2, "Error\n", 6);  
            return 1;                
        }
        j++;
    }
    return 0;
}
static bool    check_error(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while(i < argc)
        {
            j = i + 1;
            if((ft_atoi((argv[i])) > INT_MAX) || ((ft_atoi(argv[i])) < INT_MIN))
            {
                write(2, "Error\n", 6);
                return true;
            }
            if(check_double(argv, i, j, argc))
                return true;
            j = 0;
            if(check_digit(argv, i, j))
                return(true);
            i++;
        }
        return false;
}


void    init_stack(int argc, char **argv, stack **a)
{
    if(check_error(argc, argv))
        return (void)NULL;
    // if(argc == 2)
    //     argv = ft_split(argv[1], ' ');


    int i = 1;
        // if(argc == 2)
        //     i = 0;
        *a = add_node(ft_atoi(argv[i++]));
        while(i < argc)
        {
            append_node(a, add_node(ft_atoi(argv[i])));
            i++;
        }
        stack_indexing(*a);
        stack_moves(*a);
    
}