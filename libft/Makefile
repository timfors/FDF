NAME = libft.a

LIST =	ft_substr.c	ft_strjoin.c	ft_strtrim.c	ft_memset.c	ft_bzero.c	ft_strlen.c	ft_strchr.c	ft_isascii.c	ft_memcpy.c	ft_memccpy.c	ft_memmove.c	ft_memchr.c ft_memcmp.c	ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isprint.c	ft_toupper.c	ft_tolower.c	ft_strrchr.c	ft_strncmp.c	ft_strlcpy.c	ft_strlcat.c	ft_strnstr.c	ft_atoi.c	ft_calloc.c	ft_strdup.c	ft_split.c	ft_itoa.c	ft_strmapi.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c ft_lstnew.c	ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c	ft_lstclear.c	ft_lstiter.c	ft_lstmap.c ft_lstget.c ft_atoi_save.c get_next_line.c get_next_line_utils.c


HEADER = libft.h

OBJ_DIR = objects/
OBJ = $(addprefix $(OBJ_DIR), $(LIST:.c=.o))

FLAGS = -Wall -Werror -Wextra

all : $(OBJ_DIR) $(NAME)
	
$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

re : fclean all

.PHONY : all clean fclean re
