#ifndef MINISHELL_H
#define MINISHELL_H

#include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_add
{
	int type;
	char *file;
	char *limit;
	char *sep;
	char *str;
	struct s_add *next;
	struct s_add *pre;

}				t_add;

typedef struct s_help
{
	int index;
	char **cmd;
	char *herdoc;
	int fd_in;
	int fd_out;
	t_add *m;
	int exit;
	struct s_help *next;
	struct s_help *pre;

}				t_help;

typedef struct  s_env
{
	char *env;
	char *valu;
	int index;
	struct s_env *next;

} 				t_env;

t_help	*ft_lstnew(int content);
t_add	*ft_lstnew1(int content);
void	ft_lstadd_back(t_help **alst, t_help *new);
t_help	*ft_lstlast(t_help *lst);
void	ft_lstadd_back1(t_add **alst, t_add *new);
t_add	*ft_lstlast1(t_add *lst);
t_env *user_expand(char **env);
t_env	*ft_lstnew11(int content, char *ke, char *val);
void	ft_lstadd_back11(t_env **alst, t_env *new);
t_env	*ft_lstlast11(t_env *lst);

#endif
