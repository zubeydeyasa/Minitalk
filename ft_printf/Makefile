NAME	= libftprintf.a

SRCS	= ft_printf.c \
		  ft_printf_utils.c

CC = gcc

CFLAGS	= -Wall -Wextra -Werror

OBJS	= ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re