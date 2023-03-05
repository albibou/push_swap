SRCS	= ./src/main.c \
	  ./src/parse.c \
	  ./src/free.c \
	  ./src/initlist.c \
	  ./src/list_utils.c \
	  ./src/sort.c \
	  ./src/push.c \
	  ./src/rotate.c \
	  ./src/swap.c \
	  ./src/reverserotate.c \
	  ./src/trilouche.c \
	  ./src/lis.c \
	  ./src/sort_utils.c \

BONUSSRCS	= ./bonus/main_bonus.c \
		  ./bonus/check_bonus.c \
		  ./bonus/free_bonus.c \
		  ./bonus/list_utils_bonus.c \
		  ./bonus/parse_bonus.c \
		  ./bonus/rotate_bonus.c \
		  ./bonus/initlist_bonus.c \
		  ./bonus/push_bonus.c \
		  ./bonus/reverserotate_bonus.c \
		  ./bonus/swap_bonus.c \

OBJS	= ${SRCS:.c=.o}

BONUSOBJS	= ${BONUSSRCS:.c=.o}

LIBFT	= libft/libft.a

RM	= rm -f

CC	= clang

CFLAGS	= -Wall -Werror -Wextra

NAME	= push_swap 

BONUSNAME	= checker

.c.o :	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME} :	${OBJS}
		make all -C libft
		${CC} -o ${NAME} -g ${CFLAGS} ${OBJS} ${LIBFT}

${BONUSNAME} :	${BONUSOBJS}
		make all -C libft
		${CC} -o ${BONUSNAME} -g ${CFLAGS} ${BONUSOBJS} ${LIBFT}

all :		${NAME}

bonus :		${BONUSNAME}

clean :
		${RM} ${OBJS}
		${RM} ${BONUSOBJS}
		make clean -C libft

fclean :	clean
		make fclean -C libft
		${RM} ${NAME}
		${RM} ${BONUSNAME}

re :		fclean all

.PHONY :	all clean fclean re bonus
