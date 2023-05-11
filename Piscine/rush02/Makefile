CC = cc

FLAGS = -Wall -Wextra -Werror -g

SRC = $(wildcard *.c)
OBJS = $(SRC:.c=.o)

rush-02 : $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

fclean :
	rm -f *.o