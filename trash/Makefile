SRCS	= main.c \
	  instructions.c \

OBJS	= ${SRCS:.c=.o}

LIBFT	= libft/libft.a

RM	= rm -f

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

NAME	= trash 

.c.o :	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} :	${OBJS}
		clear
		@toilet -f pagga.tlf --gay "Libft"
		make all -C libft
		clear
		${CC} -o ${NAME} -g ${CFLAGS} ${OBJS} ${LIBFT}
		clear
		@toilet -f pagga.tlf --gay "Enjoy ${NAME} !"
	
all :		${NAME}

clean :
		${RM} ${OBJS}
		make clean -C libft

fclean :	clean
		make fclean -C libft
		${RM} ${NAME}

re :		fclean all

.PHONY :	all clean fclean re
