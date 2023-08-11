NAME = $(arg)

PRINTF = ft_printf/libftprintf.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(PRINTF):
	@make -C ./ft_printf

$(NAME): $(PRINTF) $(NAME).o
	@$(CC) $(CFLAGS) $(PRINTF) $(NAME).o  -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -rf *.o
	@make clean -C ./ft_printf

fclean: clean
	@rm -rf client
	@rm -rf server
	@make fclean -C ./ft_printf

re: fclean all

.PHONY: all fclean clean re