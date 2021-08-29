NAME 				= fdf
LIBFT_NAME			= libft.a
MINILIBX_NAME		= libmlx.a

HEADER				= includes/fdf.h

SRC_DIR				= source/
SRC 				= main.c
OBJ_DIR				= objects/
OBJ 				= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT_DIR			= libft/
LIBFT				= $(LIBFT_DIR)$(LIBFT_NAME)

MINILIBX_DIR		= mlx/
MINILIBX			= $(MINILIBX_DIR)$(MINILIBX_NAME)

FLAGS 				= -Werror -Wall -Wextra


all : $(OBJ_DIR) $(MINILIBX) $(LIBFT) $(NAME) 

$(OBJ_DIR)	:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o	: $(SRC_DIR)%.c $(HEADER)
	gcc $(FLAGS) -Imlx -c $< -o $@  -I ./includes/

$(NAME) : $(OBJ) $(LIBFT) $(MINILIBX)
	gcc $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ $^ -I ./includes/

$(LIBFT)	:
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)libft.h ./includes/

$(MINILIBX)	:
	$(MAKE) -C $(MINILIBX_DIR)
	cp $(MINILIBX_DIR)*.h ./includes/

fclean	: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm includes/libft.h
	rm $(NAME)

clean	:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

re : fclean all

.PHONY : all clean fclean re 
