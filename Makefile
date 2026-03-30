NAME = push_swap
CHECKER = checker

CC = cc
AR = ar rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

INCLUDE = libft

PS_SRCS = main.c\
		  ps_al_metric.c\
		  ps_al_presort.c\
		  ps_al_postsort.c\
		  ps_al_simple.c\
		  ps_al_medium.c\
		  ps_al_complex.c\
		  ps_al_special_case.c\
		  ps_op_push.c\
		  ps_op_rev_rotate.c\
		  ps_op_rotate.c\
		  ps_op_swap.c\
		  ps_parser.c\
		  ps_oplist.c\
		  ps_stack.c\
		  ps_bench.c\
		  ps_option.c\
		  ps_utils.c\

CH_SRCS = bonus.c\
		  ps_al_metric.c\
		  ps_al_presort.c\
		  ps_op_push.c\
		  ps_op_rev_rotate.c\
		  ps_op_rotate.c\
		  ps_op_swap.c\
		  ps_parser.c\
		  ps_oplist.c\
		  ps_stack.c\
		  ps_option.c\
		  ps_utils.c\

LIBFT = libft/libft.a

.DEFAULT_GOAL := all

all: $(NAME) bonus

bonus: $(CHECKER)

$(NAME): $(PS_SRCS) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(PS_SRCS) -o $@ $(INCLUDE:%=-I%) -Llibft -lft

$(CHECKER): $(CH_SRCS) $(LIBFT) Makefile
	$(CC) $(CFLAGS) $(CH_SRCS) -o $@ $(INCLUDE:%=-I%) -Llibft -lft

$(LIBFT): Makefile
	$(MAKE) -C libft libft.a

clean:
	$(MAKE) -C libft fclean

fclean: clean
	$(RM) $(CHECKER)
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean bonus run all
