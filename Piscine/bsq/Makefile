CC = clang

FLAGS = -Wall -Werror -Wextra

SRC_PATH = src/

OBJS_PATH = compil/

SRC = check.c \
	error.c \
	ft_utilitaire.c \
	matrice.c \
	recup_val.c \
	remplissage.c \
	main.c \
	appel_sol.c \
	annexe_find_carre.c \
	find_carre.c \
	in_terminal.c 

OBJS = $(SRC:.c=.o)

PREFC = $(addprefix $(SRC_PATH),$(SRC))

PREFO = $(addprefix $(OBJS_PATH),$(OBJS))

PATH_LIB = ./header

bsq : $(PREFO)
	$(CC) $(FLAGS) -o $@ $^

$(OBJS_PATH)%.o : $(SRC_PATH)%.c
	$(CC) $(FLAGS) -o $@ -c $< -I $(PATH_LIB)

fclean :
	rm -f $(PREFO)

re : fclean bsq
