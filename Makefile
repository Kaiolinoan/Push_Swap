NAME = push_swap
CC = cc
CFLAGS = -Werror -Wall -Wextra  -g -I. -I.. 
SRC_FOLDER = src
SRCS = $(addprefix $(SRC_FOLDER)/, main.c utils.c parsing.c nodes.c operations.c)
OBJS = $(SRCS:.c=.o)	

all: $(NAME)

$(NAME): $(OBJS)

	@make -s -C Libft
	@cp ./Libft/libft.a .
	@$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME)
	@echo 'Biblioteca criada'
	@echo 'Codigo compilado!'

clean:
	@find . -name '*.o' -delete
	@echo 'Objetos limpos!'

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a
	@echo  'Biblioteca limpa!'

re: fclean all