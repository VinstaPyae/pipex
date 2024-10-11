#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_ppx
{
	char	**envp;
	char	**argv;
	int		argc;
	int		fd_in;
	int		fd_out;
	int		cmd_no;
	int		p_fd[2];
	pid_t	pid;
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
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>

int	open_file(char *file, int check_flag);
void	error(void);
void	ft_free_mem(char **tab);
char	*get_emvp(char *name, char **envp);
char	*get_path(t_ppx info);

#endif
