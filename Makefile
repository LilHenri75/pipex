NAME = pipex
SRCS = sources/child.c sources/exec.c sources/pipex.c sources/validation.c ${shell find ./sources/libft -name "*.c"} ${shell find ./sources/ft_printf -name "*.c"}
BONUS = sources/exec_bonus.c sources/pipex_bonus.c ${shell find ./sources/libft -name "*.c"} ${shell find ./sources/ft_printf -name "*.c"} ${shell find ./sources/get_next_line -name "*.c"}
OBJS = $(patsubst %.c,%.o,$(SRCS))
OBJS_B = $(patsubst %.c,%.o,$(BONUS))
HEADER = -I ./includes/pipex.h
HEADER_B = -I ./includes/pipex_bonus.h
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(HEADER) $(OBJS) -o $(NAME)

bonus:		$(OBJS_B)
			@$(CC) $(CFLAGS) $(HEADER_B) $(OBJS_B) -o $(NAME)

%.o:		$(CC) $(FLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all