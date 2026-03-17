NAME = push_swap
EMUL = emul

CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

SOURCE = source
INCLUDE = include libft

PS_SRCS = src/main.c\
		  src/algo/ps_al_metric.c\
		  src/algo/ps_al_presort.c\
		  src/algo/ps_al_postsort.c\
		  src/algo/ps_al_simple.c\
		  src/algo/ps_al_medium.c\
		  src/algo/ps_al_complex.c\
		  src/oper/ps_op_push.c\
		  src/oper/ps_op_rev_rotate.c\
		  src/oper/ps_op_rotate.c\
		  src/oper/ps_op_swap.c\
		  src/ps_oplist.c\
		  src/ps_stack.c\
		  src/ps_bench.c\

EM_SRCS = src/emul.c\
		  src/oper/ps_op_push.c\
		  src/oper/ps_op_rev_rotate.c\
		  src/oper/ps_op_rotate.c\
		  src/oper/ps_op_swap.c\
		  src/ps_oplist.c\
		  src/ps_stack.c

LIBFT = libft/libft.a

.DEFAULT_GOAL := all

all: $(NAME) $(EMUL)

$(NAME): $(PS_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(PS_SRCS) -o $@ $(INCLUDE:%=-I%) -Llibft -lft

$(EMUL): $(EM_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(EM_SRCS) -o $@ $(INCLUDE:%=-I%) -Llibft -lft

$(LIBFT):
	$(MAKE) -C libft libft.a

clean:
	$(MAKE) -C libft fclean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(EMUL)

re: fclean all

.PHONY: re fclean clean all
