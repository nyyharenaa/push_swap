NAME = libft.a

CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

DEPS = libft.h
SRCS = ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_bzero.c\
	ft_memset.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlen.c\
	ft_strncmp.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strdup.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strnstr.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_printf/ft_putunb_base_fd.c\
	ft_printf/ft_putlnb_fd.c\
	ft_printf/ft_putunb_fd.c\
	ft_printf/ft_print_char_l.c\
	ft_printf/ft_print_str_l.c\
	ft_printf/ft_print_ptr_l.c\
	ft_printf/ft_print_int_l.c\
	ft_printf/ft_print_dbl_l.c\
	ft_printf/ft_print_uint_l.c\
	ft_printf/ft_print_lhex_l.c\
	ft_printf/ft_print_uhex_l.c\
	ft_printf/ft_dprintf.c\
	gnl/gnl.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(ST_LIBS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(DEPS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -I.

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
