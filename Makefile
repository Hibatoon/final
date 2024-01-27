NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
SRC = ft_atoi.c\
		add_node.c\
		append_node.c\
		list_size.c\
		init_stack.c\
		main.c\
		stack_op.c\
		tiny_sort.c\
		ra.c\
		rb.c\
		rra.c\
		rrb.c\
		push_a.c\
		push_b.c\
		swap_a.c\
		swap_b.c\
		large_sort.c\
		split_args.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY : clean fclean re 