
NAME		= so_long

LIB_PRINTF_DIR		= ./printf-V2
LIB_LIBFT_DIR		= ./libft
LIB_GETNEXTLINE_DIR	= ./getnextline
MLX_DIR				= ./minilibx_opengl
MLX					= libmlx.a

SRCS				= main.c	parse.c		create.c 	render.c
DIR_S				= src
DIR_O				= temp

REMOVE 				= rm -rf
FRAMEWORK 			= -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCLUDE				= -I./src/include -I./libft -I./printf-V2  -I./getnextline -I./minilibx_opengl 
LIB_A				= -L$(LIB_PRINTF_DIR) $(LIB_PRINTF_DIR)/libftprintf.a
LIB_B 				= -L$(LIB_LIBFT_DIR) $(LIB_LIBFT_DIR)/libft.a
LIB_C				= -L$(LIB_GETNEXTLINE_DIR) $(LIB_GETNEXTLINE_DIR)/get_next_line
CFLAGS				= -g -Wall -Wextra -Werror -fsanitize=address
DFLAGS				= 
CC					= clang


SR	=	$(addprefix $(DIR_S)/, $(SRCS))
OB	=	$(addprefix $(DIR_O)/, $(SRCS:%.c=%.o))


$(DIR_O)/%.o : $(DIR_S)/%.c
	mkdir -p temp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@ $(DFLAGS)

$(NAME) : $(OB)
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/$(MLX) .
#	make -C $(LIB_PRINTF_DIR) 
	make -C $(LIB_LIBFT_DIR)
	make -C $(LIB_GETNEXTLINE_DIR)
	$(CC) $(CFLAGS) $(OB) $(INCLUDE) $(LIB_B) $(LIB_C) $(FRAMEWORK) -o $@
	
	

all :	$(NAME)

clean	:
		$(REMOVE) $(DIR_O)
#		make clean -C $(LIB_PRINTF_DIR)
		make clean -C $(LIB_LIBFT_DIR)
		make clean -C $(LIB_GETNEXTLINE_DIR)

fclean	: clean 
	$(REMOVE) $(NAME) $(MLX) $(MLX_DIR)/$(MLX)
#	make fclean -C $(LIB_PRINTF_DIR)
	make fclean -C $(LIB_LIBFT_DIR)
	make fclean -C $(LIB_GETNEXTLINE_DIR)

re	: fclean $(NAME)

.PHONY:	all clean fclean re


#gcc -Wall -Wextra -Werror -I minilibx -L ../minilibx_opengl -lmlx -framework OpenGL -framework AppKit *.c -o output