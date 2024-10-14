/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:04:46 by pzaw              #+#    #+#             */
/*   Updated: 2024/10/14 17:04:46 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_ppx
{
	char	**env;
	char	**argv;
	int		argc;
	int		fd_in;
	int		fd_out;
	int		cmd_no;
	int		p_fd[2];
	int		status;
	pid_t	pid;
	char	**cmd;
	char	**path;
	char	*cmdpath;
}			t_ppx;

void	ft_free_mem(char **tab);
char	*get_envp(char *name, char **envp);
char	*get_path(char *cmd, t_ppx *info);
int		exec(char *c_cmd, t_ppx *info);
int		open_file(char *file, int check_flag);

#endif
