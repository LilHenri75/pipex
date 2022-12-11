NAME = pipex
SRCS = ${shell find ./sources -name "*.c"}
OBJS = $(patsubst %.c,%.o,$(SRCS))
HEADER = -I ./includes/pipex.h
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(HEADER) $(OBJS) -o $(NAME)

%.o:		$(CC) $(FLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all