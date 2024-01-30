NAME = push_swap.a
EXEC = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
EXEC_SRC = main.c
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
		split_args.c\
		is_sorted.c\
		fill_a.c\
		last_node.c
OBJ = $(SRC:.c=.o)

all : $(NAME) $(EXEC)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)

$(EXEC) : $(EXEC_SRC) $(NAME)
	$(CC) $(CFLAGS) $(EXEC_SRC) $(NAME) -o $(EXEC)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all 

.PHONY : clean fclean re 