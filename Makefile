NAME = minishell

NAME_B = minishell_bonus

MAC =

MAC_B =

LIBFT = libft

FLAGS 	=  -Wall -Wextra

LIB =  -L/usr/include -lreadline

SRCS =  	src/main_env.c\
			src/built_in/ft_free_env.c\
			src/built_in/ft_add_value.c\
			src/built_in/ft_delete_key.c\
			src/built_in/ft_get_value.c\
			src/built_in/ft_init_env.c\
			src/built_in/ft_push_front.c\
			src/built_in/ft_env_singletone.c\
			src/built_in/ft_built_in_env.c\
			src/built_in/ft_built_in_export.c\
			src/built_in/ft_built_in_unset.c\
			src/built_in/ft_built_in_pwd.c\
			src/built_in/ft_built_in_echo.c
	
SRCS_BONUS =


CC 		= gcc
OBJ 	= ${SRCS:.c=.o}
OBJS 	= *.o
OBJ_B = ${SRCS_BONUS:.c=.o}
OBJS_B = *.o

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I includes/ -I libft/includes/

all :
	@make -C $(LIBFT)
	@make $(NAME)

$(NAME)	: $(OBJ)
	$(CC) $(FLAGS) -I libft/includes/ -I includes/ $(OBJ) libft/libft.a -o $(NAME) $(LIB)

$(NAME_B) : $(OBJ_B)
	$(CC) $(FLAGS) -I libft/includes/ -I includes/ $(OBJ_B) libft/libft.a -o $(NAME_B)

clean :
		@make clean -C $(LIBFT)
		@rm -rf $(OBJ)
		@rm -rf $(OBJ_B)

fclean : clean
		@make fclean -C $(LIBFT)
		@rm -rf $(OBJS)
		@rm -rf $(OBJS_B)
		@rm -rf $(NAME)
		@rm -rf $(NAME_B)

relinux : fclean LINUX

re : fclean all

header : 
		Headermaker src includes/prototypes.h -inc structures libft

bonus :
		@make -C $(LIBFT)
		@make ${NAME_B}

rebonus : fclean bonus
