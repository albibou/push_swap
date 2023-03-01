SRCS	= ./src/main.c \
	  ./src/parse.c \
	  ./src/free.c \
	  ./src/initlist.c \
	  ./src/insert_sort.c \
	  ./src/list_utils.c \
	  ./src/sort.c \
	  ./src/push.c \
	  ./src/rotate.c \
	  ./src/swap.c \
	  ./src/reverserotate.c \
	  ./src/trilouche.c \
	  ./src/lis.c \

OBJS	= ${SRCS:.c=.o}

LIBFT	= libft/libft.a

RM	= rm -f

CC	= clang

CFLAGS	= -Wall -Werror -Wextra

NAME	= push_swap 

.c.o :	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} :	${OBJS}
		make all -C libft
		${CC} -o ${NAME} -g ${CFLAGS} ${OBJS} ${LIBFT}
	
all :		${NAME}

clean :
		${RM} ${OBJS}
		make clean -C libft

fclean :	clean
		make fclean -C libft
		${RM} ${NAME}

re :		fclean all

.PHONY :	all clean fclean re
