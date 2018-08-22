NAME		=	my_hunter

CC		=	gcc

LIB 		=	-lc_graph_prog

RM		=	rm -rf

SRC		=	src/main.c\
			src/display_and_events.c\
			src/structs.c\
			src/realhunt.c\
			src/myputstr.c\

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-Wall -Wextra -I./include 

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LD_FLAGS) $(LIB)

all:		$(NAME)

clean:
	$(RM) $(OBJ)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all
