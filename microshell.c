/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elona <elona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:30:35 by akhalidy          #+#    #+#             */
/*   Updated: 2022/03/05 00:01:41 by elona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

void	ft_print_error(char *err, char *cmd, int exiit)
{
	write(2, err, ft_strlen(err));
	if (cmd)
		write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	if (exiit)
		exit(1);
}

void	ft_cd(char **path)
{
	if (!*(path + 1) || *(path + 2))
		ft_print_error("error: cd: bad arguments", NULL, 0);
	else
		if (chdir(*(path + 1)) == -1)
			ft_print_error("error: cd: cannot change directory to ", *(path + 1), 0);
}

void	cmd_handler(char **cmd, char **envp, int in, int out, int fd[2])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_print_error("error: fatal", NULL, 1);
	if (!pid)
	{
		dup2(in, 0);
		dup2(out, 1);
		if (in)
			close(in);
		close(fd[0]);
		if (out != 1)
			close(out);
		execve(cmd[0], cmd, envp);
		ft_print_error("error: cannot execute ", cmd[0], 1);
	}
	waitpid(pid, NULL, 0);
	if (in)
		close(in);
	if (out != 1)
		close(out);
}

void	pipe_handler(char **av, char **envp)
{
	int i = 0, j;
	int fd[2];
	int still_pipe = 1;
	int out = 1, in = 0;

	while (still_pipe)
	{
		j = 0;
		char *cmd[10000];
		while (av[i] && strcmp(av[i], "|"))
		{
			cmd[j] = av[i];
			j++;
			i++;	
		}
		cmd[j] = NULL;
		still_pipe = 0;
		if (av[i])
		{
			i++;
			still_pipe = 1;
			if (pipe(fd) == -1)
				ft_print_error("error: fatal", NULL, 1);
			out = fd[1];
		}
		cmd_handler(cmd, envp, in, out, fd);
		in = fd[0];
		out = 1;
	}
}

void	comma_handler(char **av, char **envp)
{
	int i = 0, j;
	int still_comma = 1;

	while(still_comma)
	{
		char *cmd[10000];
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
			still_comma = 1;
			i++;
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
	return(0);
}