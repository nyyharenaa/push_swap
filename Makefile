NAME = push_swap
EMUL = emul

CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

SOURCE = source
INCLUDE = include libft

PS_SRCS = main.c\
		  ps_al_metric.c\
		  ps_al_presort.c\
		  ps_al_simple.c\
		  ps_al_complex.c\
		  ps_oplist.c\
		  ps_op_push.c\
		  ps_op_rev_rotate.c\
		  ps_op_rotate.c\
		  ps_op_swap.c\
		  ps_stack.c

EM_SRCS = emul.c\
		  ps_oplist.c\
		  ps_op_push.c\
		  ps_op_rev_rotate.c\
		  ps_op_rotate.c\
		  ps_op_swap.c\
		  ps_stack.c

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
