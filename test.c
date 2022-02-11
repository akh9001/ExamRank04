#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int		ft_srtlen(char *s)
{
	int i = 0;

	while(s[i])
		i++;
	return (i);
}

void	ft_print_error(char *err, char *arg, int ext)
{
	write(2, err, ft_srtlen(err));
	if (arg)
		write(2, arg, ft_srtlen(arg));
	write(2, "\n", 1);
	if (ext)
		exit(1);
}

void	ft_cd(char	**args)
{
	if (!args[0] || args[1]) // !(args[0] && !args[1])
		ft_print_error("error: cd: bad arguments\n", NULL, 0);
	else 
	{
		if (chdir(args[0]) < 0)
			ft_print_error("error: cd: cannot change directory to ", args[0], 0);
	}
}

int		cmd_handler(char **cmd, char **envp, int in, int out)
{
	int pid;

	pid = fork();
	if (!pid)
	{
		dup2(in, 0);
		dup2(out, 1);
		if (in)
			close(in);
		if (out != 1)
			close(out);
		if (!strcmp(cmd[0], "cd"))
				ft_cd(cmd + 1);
		else
			execve(cmd[0], cmd, envp);
		ft_print_error("error: cannot execute ", cmd[0], 1);
	}
	if (in)
		close(in);
	if (out != 1)
		close(out);
	return (pid);
}


void	pipe_handler(char **s, char **envp)
{
	int i = 0, j;
	int	fd[2];
	int in = 0, out = 1;
	int	still_pipe = 1;

	while(still_pipe)
	{
		char *cmd[500];
		j = 0;
		out = 1;
		while (s[i] && strcmp("|", s[i]))
		{
			cmd[j] = s[i];
			j++;
			i++;
		}
		cmd[j] = NULL;
		still_pipe = 0;
		if(s[i])
		{
			still_pipe = 1;
			i++;
			pipe(fd);
			out = fd[1];
		}
		int pid = cmd_handler(cmd, envp, in, out);
		waitpid(pid, NULL, 0);
		in = fd[0];
	}
}

void		comma_handler(char **s, char **envp)
{
	int	still_comma = 1;
	int i = 0;
	int	j;

	while(still_comma)
	{
		j = 0;
		char *cmd[500];
		while (s[i] && strcmp(s[i], ";"))
		{
			cmd[j] = s[i];
			j++;
			i++; 
		}
		cmd[j] = NULL;
		still_comma = 0;
		if (s[i])
		{
			still_comma = 1;
			i++;
		}
		if (cmd[0])
		{
			if (!strcmp(cmd[0], "cd"))
				ft_cd(cmd + 1);
			else
				pipe_handler(cmd, envp);
		}
	}
}

int main(int ac, char **av, char **envp)
{
	(void)ac;
	comma_handler(av + 1, envp);
	return(0);
}


