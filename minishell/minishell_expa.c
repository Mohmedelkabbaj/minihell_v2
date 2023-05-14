#include "minishell.h"

t_env	*ft_lstnew11(int content, char *ke, char *val)
{
	t_env	*node;

	node = (t_env *)malloc(sizeof(*node));
	if (!(node))
		return (NULL);
	node->index = content;
	node->env = ke;
	node->next = NULL;
	node->valu = val;
	return (node);
}
t_env	*ft_lstlast11(t_env *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back11(t_env **alst, t_env *new)
{
	t_env	*last;

	if (alst)
	{
		if (*alst)
		{
			last = ft_lstlast11(*alst);
			last->next = new;
		}
		else
			*alst = new;
	}
}

int	cherch_equal(char *env)
{
	int i;

	i = 0;
	while (env[i] != '\0')
	{
		if (env[i] == '=')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

t_env *user_expand(char **env)
{
	char *ret;
	t_env *en = NULL;
	int i;
	int j;
	int m;

	i = 0;

	while (env[i] != '\0')
	{
		j = cherch_equal(env[i]);
		if (j != -1)
		{
			ret = malloc(sizeof(char) * (j + 1));
			m = 0;
			while (m < j)
			{
				ret[m] = env[i][m];
				m++;
			}
			ret[m] = '\0';
		}
		ft_lstadd_back11(&en, ft_lstnew11(i, ret, ft_strdup(env[i] + j + 1)));
		i++;
	}
	return (en);
}

char *ft_skip(char **cmd)
{
	int i;
	int j;
	int k;
	char *s;

	i = 0;
	k = 0;
	s = ft_calloc(sizeof(char) * ft_strlen(cmd[i]),1);
	while (cmd[i])
	{
		j = 0;
		if (cmd[i][j] >= '"')
		{
			j++;
		}
		else
		{
			s[k] = cmd[i][j];
			j++;
			k++;
		}
		i++;
	}
	return (s);
}
