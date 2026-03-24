NAME = push_swap
CHECKER = checker_linux
CHECKER_LNK = https://cdn.intra.42.fr/document/document/47392/checker_linux

CC = cc
AR = ar rcs
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror -g

INCLUDE = include libft

PS_SRCS = main.c\
		  ps_al_metric.c\
		  ps_al_presort.c\
		  ps_al_postsort.c\
		  ps_al_simple.c\
		  ps_al_medium.c\
		  ps_al_complex.c\
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

LIBFT = libft/libft.a

NB_COUNT = 100
ARG := $(shell shuf -i 0-2000 -n $(NB_COUNT) | tr '\n' ' ')

.DEFAULT_GOAL := all

all: $(NAME)

$(NAME): $(PS_SRCS) $(LIBFT)
	$(CC) $(CFLAGS) $(PS_SRCS) -o $@ $(INCLUDE:%=-I%) -Llibft -lft

$(LIBFT):
	$(MAKE) -C libft libft.a

$(CHECKER):
	@wget $(CHECKER_LNK)

run: $(NAME) $(CHECKER)
	@chmod u+x $(CHECKER)
	@echo "ARG: \e[2m$(ARG)"
	@echo -n $(ARG) > input.txt
	@echo -n "\e[0;1mSolution: \e[32m"
	@./$(NAME) $(ARG) --medium 1> output.txt 2> bench.txt
	@./$(CHECKER) $(ARG) < output.txt

clean:
	$(RM) *.txt
	$(RM) $(CHECKER)
	$(MAKE) -C libft fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean run all
