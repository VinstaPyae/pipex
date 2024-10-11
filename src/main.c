#include "pipex.h"

void	init(t_ppx *info, int argc, char **argv, char **envp)
{
	info->envp = envp;
	info->argv = argv;
	info->argc = argc;
	info->fd_in = open_file(argv[1], 0);
	if (info->fd_in == -1)
		error();
	info->fd_out = open_file(argv[argc - 1], 1);
	if (info->fd_out == -1)
		error();
}
void	exec(char *c_cmd, t_ppx *info)
{
	info->cmd = ft_split(c_cmd, ' ');
	info->cmdpath = get_path(info);
	if (execve(info->cmdpath, info->cmd, info->envp) == -1)
	{
		ft_free_mem(info->cmd);
		error();
	}
}

void	child(t_ppx *info)
{
	dup2(info->fd_in, 0);
	dup2(info->p_fd[1], 1);
	close(info->p_fd[0]);
	exec(info->argv[2], info);
}

void	parent(t_ppx *info)
{
	dup2(info->fd_out, 1);
	dup2(info->p_fd[0], 0);
	close(info->p_fd[1]);
	exec(info->argv[3], info);
}

int	main(int argc,char *argv[], char **envp)
{
	t_ppx info;

	if (argc == 5)
	{
		if (pipe(info->p_fd) == -1)
			error();
		init(info, argc, argv, envp);
		info->pid = fork();
		if (info->pid == -1)
			error();
		if (info->pid == 0)
			child(&info);
		else
			parent(&info);
	}
	else
	{
		ft_printf("\033[31mError: Bad arguments\n\e[0m");
		ft_printf("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n");
	}
	return (0);
}
