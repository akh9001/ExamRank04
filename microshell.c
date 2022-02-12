/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:30:35 by akhalidy          #+#    #+#             */
/*   Updated: 2022/02/12 22:11:32 by akhalidy         ###   ########.fr       */
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
		ft_print_error("error: cd: bad arguments", NULL, 1);
	if (chdir(*(path + 1)) == -1)
		ft_print_error("error: cd: cannot change directory to ", *(path + 1), 1);
}

void	cmd_handler(char **cmd, char **envp, int in, int out, int fd[2])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		ft_print_error("error: fatal", NULL, 1);
	//! fprintf(stderr, "\033[0;31m %s +++++ %s \033[0m\n", cmd[0], cmd[1]);
	if (!pid)
	{
		dup2(in, 0);
		dup2(out, 1);
		if (in)
			close(in);
		// else // I guess i should remove this else
		close(fd[0]);
		if (out != 1)
			close(out);
		// else
		// 	close(fd[1]);
		execve(cmd[0], cmd, envp);
		ft_print_error("error: cannot execute ", cmd[0], 1);
	}
	waitpid(pid, NULL, 0);
	if (in)
		close(in);
	if (out != 1)
		close(out);
	// else
	// 	close (fd[1]);
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
		char *cmd[500];
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
			//! write(1, "\033[0;32m Ba3ouuuuda \033[0m\n", ft_strlen("\033[0;32m Ba3ouuuuda \033[0m\n"));
		//!fprintf(stderr, "\033[0;32m %d %s 11111 %s \033[0m\n", i, av[i], cmd[1]);
		if (av[i])
		{
			still_comma = 1;
			i++;
		}
		//!fprintf(stderr, "\033[0;31m %d %s 22222 %s \033[0m\n", i, cmd[0], cmd[1]);
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