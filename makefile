CC	= gcc

NAME	= debug

SRC	= main.c func/error.c func/init.c func/game.c

FLAG	= -W -Wall -Werror

OBJ	= $(SRC:%.c=%.o)

RM	= rm -f

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(FLAG)

all:		$(NAME)

clean:		
		$(RM) $(OBJ)
fclean:		clean
		$(RM) $(NAME)
