#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_ppx
{
	char	**envp;
	char	**argv;
	int		argc;
	int		heredoc;
	int		fd_in;
	int		fd_out;
	int		cmd_no;
	int		oldpipe[2];
	int		newpipe[2];
//	pid_t	pid;
	int		child;
	char	**cmd;
	char	**path;
	char	*cmdpath;
}			t_ppx;

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

#endif
