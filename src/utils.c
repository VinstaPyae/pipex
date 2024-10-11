#include "pipex.h"

int	exec(char *c_cmd, t_ppx *info)
{
	info->cmd = ft_split(c_cmd, ' ');
	info->cmdpath = get_path(info->cmd[0],info);
	if (execve(info->cmdpath, info->cmd, info->env) == -1)
	{
		ft_putstr_fd("Command not found\n", 2);
		ft_free_mem(info->cmd);
		return (0);
	}
	return(1);
}

int	open_file(char *file, int check_flag)
{
	int	rnum;

	if (check_flag == 0)
		rnum = open(file, O_RDONLY, 0777);
	else
		rnum = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	return (rnum);
}

void	error(void)
{
	perror("\033[31mError");
}

void	ft_free_mem(char **tab)
{
	size_t	i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_envp(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strncmp(sub, name, ft_strlen(name)) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, t_ppx *info)
{
	int		i;
	char	*ret;
	char	*path_part;
	char	**s_cmd;
	
	i = -1;
	s_cmd = ft_split(cmd, ' ');
	info->path = ft_split(get_envp("PATH", info->env), ':');
	while(info->path[++i])
	{
		path_part = ft_strjoin(info->path[i], "/");
		ret = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(ret, F_OK | X_OK) == 0)
		{
			ft_free_mem(s_cmd);
			return(ret);
		}
		free(ret);
	}
	ft_free_mem(info->path);
	ft_free_mem(s_cmd);
	return(info->cmd[0]);
}
