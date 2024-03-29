NAME = push_swap.a
EXEC = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
AR = ar rcs
EXEC_SRC = main.c

SRC = ft_atoi.c add_node.c append_node.c list_size.c init_stack.c stack_op.c tiny_sort.c ra.c\
		rb.c rra.c rrb.c push_a.c push_b.c swap_a.c swap_b.c large_sort.c\
		is_sorted.c fill_a.c last_node.c count_word.c main.c separate.c large_helper.c\
		large_sort_utils.c arr.c ft_split.c a_to_b_helper.c fill_helper.c split_helper.c
BSRC = actions_a.c actions_b.c both_actions_bonus.c ft_atoi_bonus.c init_stack_bonus.c\
		get_next_line.c get_next_line_utils.c add_node_bonus.c append_node_bonus.c\
		count_word_bonus.c stack_op_bonus.c ft_strcmp.c checker_utils.c\
		
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

all : $(NAME) $(EXEC)
bonus : $(BOBJ)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) -c $(SRC)
$(BOBJ) : $(BSRC)
	$(CC) $(CFLAGS) -c $(BSRC)
	$(AR) $(NAME) $(BOBJ)
	$(CC) $(CFLAGS) checker.c -o checker $(NAME)

$(EXEC) : $(EXEC_SRC) $(NAME)
	$(CC) $(CFLAGS) $(EXEC_SRC) $(NAME) -o $(EXEC)

clean :
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	rm -f $(NAME) $(EXEC) checker

re : fclean all 

.PHONY : clean fclean re 