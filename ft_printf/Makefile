CC = cc

CFLAGS = -Wall -Werror -Wextra -I.

SRC = ft_printf.c \
	ft_aff.c \
	ft_convert_base.c \
	ft_case.c

SRC_LIBFT = ft_isdigit.c \
	ft_putendl_fd.c \
	ft_strjoin.c \
	ft_strrchr.c \
	ft_atoi.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_putnbr_fd.c \
	ft_strlcat.c \
	ft_strtrim.c \
	ft_bzero.c \
	ft_itoa.c \
	ft_memcmp.c \
	ft_putstr_fd.c \
	ft_strlcpy.c \
	ft_substr.c \
	ft_calloc.c \
	ft_memcpy.c \
	ft_split.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_isalnum.c \
	ft_memmove.c \
	ft_strchr.c \
	ft_strmapi.c \
	ft_toupper.c \
	ft_isalpha.c \
	ft_memset.c \
	ft_strdup.c \
	ft_strncmp.c \
	ft_isascii.c \
	ft_putchar_fd.c \
	ft_striteri.c \
	ft_strnstr.c \
	ft_itoa_unsigned.c

SRC_LIBFT_PATH = libft/

PREFC = $(addprefix $(SRC_LIBFT_PATH),$(SRC_LIBFT))

OBJS = $(SRC:.c=.o)

OBJS_LIBFT = $(PREFC:.c=.o)

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS) $(OBJS_LIBFT)
	ar rcs $(NAME) $(OBJS)
	ar rcs $(NAME) $(OBJS_LIBFT)

clean :
	rm -f $(OBJS) $(OBJS_LIBFT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re