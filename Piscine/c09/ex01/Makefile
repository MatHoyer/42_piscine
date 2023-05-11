CC = gcc

FLAGS = -Wall -Wextra -Werror

SRCS_PATH = srcs/

OBJS_PATH = srcs/

HEADER_PATH = ./includes

SRCS =  ft_putchar.c \
	ft_swap.c ft_putstr.c \
	ft_strlen.c \
	ft_strcmp.c

OBJS = $(SRCS:.c=.o)

PREFC = $(addprefix $(SRCS_PATH), $(SRCS))

PREFO = $(addprefix $(OBJS_PATH), $(OBJS))

PROG = libft.a

$(PROG) : $(PREFO)
	ar rc -o $(PROG) $^

all : $(PROG)

$(PREFO) : $(PREFC)
	$(CC) $(FLAGS) -o  $@ -c $< -I $(HEADER_PATH)

clean :
	rm -f $(PREFO)

fclean : clean
	rm -f $(PROG)

re : fclean all

.PHONY : fclean clean
