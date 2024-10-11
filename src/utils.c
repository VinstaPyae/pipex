#include "pipex.h"

int	open_file(char *file, int check_flag)
{
	int	rnum;

	if (check_flag == 0)
		rnum = open(file, O_RDONLY, 0777);
	else if (check_flag == 1)
		rnum = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (rnum == -1)
		exit(0);
	return (rnum);
}

void	error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	ft_free_mem(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*get_envp(char *name, char **envp)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		sub = ft_substr(envp[i], 0, j);
		if (ft_strncmp(sub, name, ft_strlen(name)) == 0)
		{
			free(sub);
			return (envp[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}
//need to fix
char	*get_path(t_ppx *info)
{
	int		i;
	char	*ret;
	char	**path_part;
	
	i = -1;
	info->path = ft_split(get_envp("PATH", info->envp), ':');
	while(info->path[++i])
	{
		path_part = ft_strjoin(info->path[i], "/");
		ret = ft_strjoin(path_part, info->cmd[0]);
		free(path_part);
		if (access(ret, F_OK | X_OK) == 0)
		{
			ft_free_mem(info->cmd);
			return(ret);
		}
		free(ret);
	}
	ft_free_mem(info->path);
	ft_free_mem(info->cmd);
	return((char *)info->cmd);
}
