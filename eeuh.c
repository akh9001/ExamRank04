#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_print_error(char *err, char *cmd)
{
	write(2, err, ft_strlen(err));
	if (cmd)
		write(2, cmd, ft_strlen(cmd));
	write(2, "\n", ft_strlen("\n"));
}

void	comma_handler(char ** av, char *envp)
{
	int	i = 0, j;
	int still_comma = 1;

	while (still_comma)
	{
		char *cmd[5000];
		j = 0;
		while (av[i] && strcmp(av[i], ";"))
		{
			cmd[j] = av[i];
			j++;
			i++;
		}
		cmd[j] = NULL;
		still_comma = 0;
		if (av[i])
		{
			i++;
			still_comma = 1;
		}
		if (cmd[0])
		{
			if (!strcmp(cmd[0], "cd"))
				ft_cd(cmd);
			else
				pipe_handler(cmd, envp);
		}
	}
}

int main(int ac, char **av, char **envp)
{
	if (ac < 2)
		return(0);
	comma_handler(av + 1, envp);
}