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
	  ./src/accorns_sort.c \
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
		  ./bonus/reverse_rotate_bonus.c \
		  ./bonus/swap_bonus.c \

OBJS	= ${SRCS:.c=.o}

BONUSOBJS	= ${BONUSSRCS:.c=.o}

INCLUDES	= ./includes/

LIBFT	= libft/libft.a

RM	= rm -f

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

NAME	= push_swap 

BONUSNAME	= checker

.c.o :	
		${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o ${<:.c=.o}

${NAME} :	${OBJS}
		clear
		@toilet -f pagga.tlf --gay "Libft"
		make all -C libft
		clear
		${CC} -o ${NAME} -g ${CFLAGS} ${OBJS} ${LIBFT}
		clear
		@toilet -f pagga.tlf --gay "Enjoy ${NAME} !"

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
