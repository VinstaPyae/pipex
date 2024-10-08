#include "pipex.h"

void	init(t_ppx *info, int argc, char **argv, char **envp)
{
	info->envp = envp;
	info->argv = argv;
	info->argc = argc;
	info->heredoc = ft_strncmp("here_doc", argv[1], 9);
}


int	main(int argc,char *argv[], char **envp)
{
	t_ppx info;

	if (argc < 5)
		return (ft_printf("Input command not enough!!"));
	else if (ft_strncmp("here_doc", argv[1], 9) && argc < 6)
		return (ft_printf("It is here doc!\n"));
	init(&info, argc, argv, envp);
	return (0);
}