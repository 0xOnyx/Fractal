
NAME		= fractol
SRC		= src/app.c
OBJECT_O	= app.o
WARNING 	= -Wall -Wextra -Werror

all: $(NAME)


$(NAME): compile link

compile:
	gcc -I/usr/include -Imlx_linux -O3 -c $(SRC)

link:
	gcc -o $(NAME) $(OBJECT_O) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

re: fclean all

clean: 
	/bin/rm -f $(OBJECT_O)

fclean: clean
	/bin/rm -f $(NAME)
