NAME = push_swap

NAME1 = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror 

SRC = arg_check.c best_move.c ft_atoi.c p_utils.c pa.c pb.c push_swap.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c sort_3.c sort_5.c sort.c ss.c 

BSRC = checker.c get_next_line.c get_next_line_utils.c arg_check.c ft_atoi.c p_utils.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c rrr.c sa.c sb.c ss.c 

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) pushswap.h
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME1)
	
$(NAME1) : $(BOBJ) 
	@$(CC) $(CFLAGS) $(BOBJ) -o $(NAME1)
clean :
	@-rm -rf $(BOBJ) $(OBJ)
fclean : clean
	@-rm $(NAME) $(NAME1)
re : fclean all

.PHONY : clean fclean re all bonus