#include "pipex.h"

void	child(t_ppx *info)
{
	if (info->fd_in == -1)
		return ;
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

void	init(t_ppx *info, int argc, char **argv, char **envp)
{
	info->env = envp;
	info->argv = argv;
	info->argc = argc;
	info->fd_in = open_file(argv[1], 0);
	info->fd_out = open_file(argv[argc - 1], 1);
	if (info->fd_in == -1)
	{
		perror("Error opening file");
	}
	if (pipe(info->p_fd) == -1)
	{
		perror("\033[31mError");
		return ;
	}
	info->pid = fork();
	if (info->pid == -1)
	{
		perror("\033[31mError");
		return ;
	}
	choose_process(info);
}

void	choose_process(t_ppx *info)
{
	if (info->pid == 0)
		child(info);
	else
	{
		waitpid(info->pid, &info->status, 0);
		if (WIFEXITED(info->status) && WEXITSTATUS(info->status) != 0)
		{
			write(info->fd_out, "0\n", 2);
			close(info->fd_out);
		}
		else
		{
			parent(info);
		}
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_ppx	info;

	if (argc == 5)
		init(&info, argc, argv, envp);
	else
		ft_printf("\033[31mError: Bad arguments\n\e[0m");
	return (0);
}
