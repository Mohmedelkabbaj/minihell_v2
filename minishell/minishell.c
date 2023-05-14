#include "minishell.h"
int calc_space(char *s , char c)
{
	int i = 0;
	int j = 0;

	while(s[i])
	{
		if(s[i] == c)
		{
			if(s[i - 1] != ' ')
			{
				j += 1;
			}
			if(s[i + 1] != ' ' && s[i + 1] != '\0')
			{
				j += 1;
			}
		}
		i++;
	}
	return(j + i);
}

char *ft_add_space(char *s)
{
	int i;
	int j;
	int len;
	char *src;

	i = 0;
	j = 0;
	len = calc_space(s, '|');
	src = ft_calloc(sizeof(char) * len,1);
	while (s[i])
	{
		while(s[i] == '"')
		{
			i++;
			if(s[i] == '"')
			{
				break;
			}
		}
		if (s[i] == '|' && s[i - 1] == ' ' && s[i + 1] == ' ')
			src[j++] = s[i++];
		if (s[i] == '|' && s[i - 1] != ' ')
		{
			src[j++] = ' ';
			src[j++] = '|';
			i++;
		}
		if (s[i - 1] == '|' && s[i] != ' ')
			src[j++] = ' ';
		src[j++] = s[i++];
	}
	src[j] = '\0';
	return (src);
}

char *ft_add_space2(char *s)
{
	int i;
	int j;
	int len;
	char *src;

	i = 0;
	j = 0;
	len = calc_space(s, '<');
	src = ft_calloc(sizeof(char) * len,1);
	while (s[i])
	{
		while(s[i] == '"')
		{
			i++;
			if(s[i] == '"')
			{
				break;
			}
		}
		if (s[i] == '<')
		{
			if (i != 0 && s[i - 1] != ' ')
				src[j++] = ' ';
			src[j++] = s[i++];
			if (s[i] == '<')
				src[j++] = s[i++];
			if (s[i] != ' ')
				src[j++] = ' ';
		}
		src[j++] = s[i++];
	}
	src[j] = '\0';
	return (src);
}

char *ft_add_space3(char *s)
{
	int i;
	int j;
	int len;
	char *src;

	i = 0;
	j = 0;
	len = calc_space(s, '>');
	src = ft_calloc(sizeof(char) * len,1);
	while (s[i])
	{
		while(s[i] == '"')
		{
			i++;
			if(s[i] == '"')
			{
				break;
			}
		}
		if (s[i] == '>')
		{
			if (i != 0 && s[i - 1] != ' ')
				src[j++] = ' ';
			src[j++] = s[i++];
			if (s[i] == '>')
				src[j++] = s[i++];
			if (s[i] != ' ')
				src[j++] = ' ';
		}
		src[j++] = s[i++];
	}
	src[j] = '\0';
	return (src);
}


// t_add ft_checkerror(char *s)
// {
// 	int i;

// 	i = 0
// 	int len = ft_strlen(s) - 1;
// 	while(s[i])
// 	{
// 		if(i == len && s[len] = '|')
// 		{
// 			printf("bash: syntax error near unexpected token `|'");
// 			exit(1);
// 		}
// 		i++;
// 	}
// }

int ft_send(char *s , t_add **l)
{
	int	i;

	t_add *p;
	p = *l;


	if (ft_strcmp(s, "<<") == 0)
		p->type = 4;
	else if (ft_strcmp(s, ">>") == 0)
		p->type = 2;
	else if (ft_strchr(s, '<') != 0)
		p->type = 3;
	else if (ft_strchr(s, '>') != 0)
		p->type = 3;
	else
		return(0);
	return(1);

}

t_help *rempl(char *m,  t_help **l)
{
	int i = 0;
	int j;
	t_help *p = *l;
	char **str;
	char *line;

	j = 0;
	p->m = ft_lstnew1(0);
	str = ft_split(m, ' ');
	while(str[i])
	{
		if(ft_send(str[i], &p->m) == 1)
		{
			p->m->sep = str[i];
			if(p->m->type == 3 && str[i+1])
			{
				p->m->file = str[i + 1];
				p->fd_out = open(str[i + 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
				if (p->fd_out == -1)
					perror(p->m->file);
			}
			else if(p->m->type == 1 && str[i+1])
			{
				p->m->file = str[i + 1];
				p->fd_in = open(str[i + 1], O_RDONLY, 0666);
				if (p->fd_out == -1)
					perror(p->m->file);
			}
			else if(p->m->type == 2 && str[i+1])
			{
				p->m->file = str[i + 1];
				p->fd_out = open(str[i + 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
				if (p->fd_out == -1)
					perror(p->m->file);
			}
			else if(p->m->type == 4 && str[i+1])
			{
				p->m->limit = str[i + 1];
				p->fd_in = open("/tmp/heredoc",  O_CREAT | O_TRUNC | O_WRONLY, 0666);
				line = readline("> ");
				while (line != NULL)
				{
					ft_putstr_fd(line, p->fd_in);
					if (!ft_strcmp(line, p->m->limit))
						break;
					free(line);
					line = readline("> ");
				}
			}
			i++;
			printf("type=======%d==========\n",p->m->type);
			printf("limit=======%s==========\n",p->m->limit);
			printf("file=======%s==========\n",p->m->file);
			printf("sep=======%s==========\n",p->m->sep);
			if(!str[i])
				break;
			j++;
			ft_lstadd_back1(&p->m,ft_lstnew1(j));
			p->m = p->m->next;
			p->m->str = p->m->pre->str;
		}
		else
		{
			p->m->str = ft_strjoin(p->m->str,str[i]);
		printf("str=======%s==========\n",p->m->str);
			//i++;

		}
		i++;
	}
	return (p);
}

void ft_checkerror(char *str)
{
	int i;
	int len = ft_strlen(str) - 1;

	i = 0;
	while(str[i])
	{
		if(str[i] == '|')
		{
			printf("bash: syntax error near unexpected token `|'\n");
			exit(1);
		}
		if(str[i] == '"')
		{
			while(str[++i])
			{
				if(str[i] == '"')
				{
					break;
				}
				else
				{
					printf("bash: unexpected EOF while looking for matching `\n");
					printf("bash: syntax error: unexpected end of file\n");
					exit(1);
				}
			}
		}
		if(str[i] == '|')
		{
			while(str[++i] == ' ')
			{
				if(str[i] != '|')
				{
					break;
				}
				else
				{
					printf("bash: syntax error near unexpected token `|'\n");
					exit(1);
				}
			}
		}
		if(str[i] == '|' && str[i + 1] == '|')
		{
			printf("bash: syntax error near unexpected token `|'\n");
			exit(1);
		}
		i++;
	}
}

int calcu_upper(char *cmd)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (cmd[i])
	{
		if(cmd[i] >= 'A' && cmd[i] <= 'Z')
		{
			k++;
		}
		i++;
	}
	return(k);
}

int calcu_lower(char *cmd)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (cmd[i])
	{
		if(cmd[i] != '$')
		{
			k++;
		}
		else
			break;
		i++;
	}
	return(k);
}

// int ft_help_str(char **cmd)
// {
// 	int i;
// 	int j;
// 	int k;
// 	char *s;

// 	i = 0;
// 	k = 0;
// 	s = NULL;
// 	if(!cmd)
// 		return(0);
// 	while(cmd[i])
// 	{
// 		j = 0;
// 		while(cmd[i][j])
// 		{
// 			if(cmd[i][j] != '$')
// 			{
// 				j++;
// 			}
// 		}
// 		i++;
// 	}
// 	printf("j= %d",j);
// 	// while(cmd[i])
// 	// {
// 	// 	j = 0;
// 	// 	while(cmd[i][j])
// 	// 	{
// 	// 		if(cmd[i][j] != '$')
// 	// 		{
// 	// 			s[k] = cmd[i][j];
// 	// 			k++;
// 	// 		}
// 	// 		j++;
// 	// 	}
// 	// 	i++;
// 	// }
// 	// printf("str==%s",s);
// 	return(j);
// }

// char *ft_join_after(char **cmd)
// {

// }

int calcu_valu(char *str)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while(str[i])
	{
		if(str[i] >= 33 && str[i] <= 47)
		{
			if(str[i] == '$')
			{
				i++;
			}
			else
			{
				k = i;
				return(k);
			}
		}
		i++;
	}
	return(0);
}

// char *ft_skip(char *cmd, int *i)
// {
// 	while(cmd[i])
// 	{
// 		if(cmd[i] == '"')
// 		{
// 			i++;
// 		}
// 	}
// 	return(i);
// }

// char *ft_env_value(t_env *en, char **cmd)
// {
// 	int i;
// 	char *tmp_str;
// 	char *ret;
// 	char *s;
// 	size_t m;
// 	t_env	*e;
// 	int k;
// 	char *o;
// 	int ss;
// 	int j;

// 	i = 0;
// 	e = en;
// 	ret = NULL;
// 	//cmd = ft_split(cmd[i],' ');
// 	while(cmd[i])
// 	{
// 		j = 0;
// 		while(cmd[i][j])
// 		{
// 			if(cmd[i][j] == '$')
// 			{
// 				k = calcu_upper(cmd[i]);
// 				m = calcu_lower(cmd[i]);
// 				tmp_str = ft_substr(cmd[i], j + 1, k);
// 				s = ft_substr(cmd[i],0,m);
// 				ss = calcu_valu(cmd[i]);
// 				en = e;
// 				while (en->next)
// 				{
// 					if(!ft_strcmp(tmp_str, en->env))
// 					{
// 						// ret = malloc(sizeof(char) * (ft_strlen(en->valu) + m));
// 						//ret = ft_strjoin1(ret,)
// 						ret = ft_strjoin1(s,en->valu);
// 						if(ss)
// 						{
// 							//tmp_str = NULL;
// 							o = ft_substr(cmd[i],ss,ft_strlen(cmd[i]));
// 							ret = ft_strjoin1(ret,o);
// 						}
// 						// else
// 						// 	ret = ft_strjoin1(ret,en->valu);
// 						tmp_str = ft_strjoin1(tmp_str,ret);
// 						//return(ret);
// 					}
// 					en = en->next;
// 				}
// 			}
// 			j++;
// 		}
// 		i++;
// 		//i++;
// 	}
// 	// if(cmd[i + 1])
// 	// {
// 	// 	ret = ft_strjoin(cmd[i],cmd[i + 1]);
// 	// }
// 	if(ret)
// 		return(ret);
// 	return(NULL);
// }

char *ft_env_value(t_env *en, char **s)
{
	int i;
	char *tmp_str = NULL;
	char *ret;
	char *cmd;
	size_t m;
	t_env *sa = en;
	int k;
	int j;

	i = 0;
	while(s[i])
	{
		j = 0;
		while(s[i][j])
		{
			if(s[i][j] == '$')
			{
				k = calcu_upper(s[i]);
				m = calcu_lower(s[i]);
				en = sa;
				while (en->next)
				{
					tmp_str = ft_substr(s[i],j + 1,k);
					if(!ft_strcmp(tmp_str, en->env))
					{
						if(j < k)
						{
							cmd = ft_substr(s[i], 0, m);
							ret = ft_strjoin(cmd, en->valu);
							//printf("cmd = %s=======%s",cmd,en->valu);
						}
						else if(j > k)
						{
							ret = ft_strjoin1(ret,en->valu);
						}
						printf("*****ret%s",ret);
						// exit(1);
						//return(ret);
					}
					// else
					// {
					// 	ret = ft_strdup(s[i]);
					// 	//tmp_str = ft_strjoin(tmp_str,s[0]);
					// }
					//tmp_str = ft_strjoin1(tmp_str,ret);
					en = en->next;
				}
			}
			j++;
		}
		i++;
	}
	if(ret)
	{
		return(ret);
	}
	return(NULL);
}

int main(int ac, char **av, char **env)
{
	char	*buff;
	char **tmp;
	t_help *m;
	t_help *sa;
	t_env *en;
	char *user;
	char *value;

	m = ft_lstnew(0);
	char *s;

	buff = NULL;
	(void)ac;
	(void)av;
	int i;
	int j;

	while (1)
	{
		j = 0;
		i = 0;
		buff = readline("minishell>");
		add_history(buff);
		if (!buff)
			return (0);
		//ft_checkerror(buff);
		while (buff[i])
		{
			if (buff[i] == '|' || buff[i] == '<' || buff[i] == '>')
			{
				if (buff[i] == '|')
					buff = ft_add_space(buff);
				else if (buff[i] == '<' || (buff[i] == '<' && buff[i + 1] == '<'))
				 	buff = ft_add_space2(buff);
				else if (buff[i] == '>' || (buff[i] == '>' && buff[i + 1] == '>'))
				 	buff = ft_add_space3(buff);
			}
			i++;
		}
		i = -1;
		sa = m;
		tmp = ft_split(buff, '|');
		en = user_expand(env);
		while (tmp[++i])
		{
			m->index = i;
			rempl(tmp[i], &m);
			m->cmd = ft_split(m->m->str, '\n');
			ft_lstadd_back(&m, ft_lstnew(i));
			m->cmd[i] = ft_env_value(en, m->cmd);
			printf("cmd==%s===%s==\n",m->cmd[0],m->cmd[1]);
			m = m->next;
		}
		if(m->cmd)
		{
			printf("***%s**\n",m->cmd[i]);
		}
	}
}
