SRCS			=	libft/ft_bzero.c libft/ft_isascii.c libft/ft_isprint.c libft/ft_memcmp.c libft/ft_memmove.c libft/ft_strchr.c\
					libft/ft_strlen.c libft/ft_strnstr.c libft/ft_tolower.c libft/ft_calloc.c libft/ft_isalpha.c libft/ft_isdigit.c lists.c\
					libft/ft_memchr.c libft/ft_memcpy.c libft/ft_memset.c libft/ft_strdup.c libft/ft_strncmp.c libft/ft_strrchr.c libft/ft_toupper.c libft/ft_strstr.c\
					libft/ft_isalnum.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_atoi.c libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c\
					libft/ft_strcmp.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_striteri.c\
					minishell.c minishell_expa.c

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAG			= -lreadline -fsanitize=address -g3

NAME			= minishell

all:			$(NAME)

$(NAME):		$(OBJS)
				@(CC) $(CFLAG) $(OBJS) -o $(NAME)

.c.o: $(SRCS)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)
