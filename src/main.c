#include "pipex.h"

int	main(int argc,char *argv[])
{
	ft_printf("%d\n", argc);
	if (argc < 5)
		return (ft_printf("Input command not enough!!"));
	if (!ft_strncmp("here_doc", argv[1], 9))
		return (ft_printf("It is here doc!\n"));
	return (0);
}