/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hmmm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:53:14 by akhalidy          #+#    #+#             */
/*   Updated: 2022/01/05 11:27:19 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
		i++;
	return(i);
}

void	ft_print_err(char *err, char cmd, int ext)
{
	write(2, err, ft_srlen(err));
	if (cmd)
		write(2, cmd, ft_srlen(cmd));
	write(2, "\n", 1);
	if (ext)
		exit(1);
}

void	ft_cd(char **path, int ext)
{
	if (!*path[0] || *path[1])
		ft_print_err("error: cd: bad arguments", NULL, ext);
	if (chdir(*path[0]))
 		ft_print_err("error: cd: cannot change directory to ", *path[0], ext);
	if (ext)
		exit(0);
}

int	cmd_handler(char **cmd, char **env, int in, int out)
{
	int	pid;

	pid = fork();
	if (!pid)
	{
		dup2(in, 0);
		dup2(out, 1);
		if (in)
			close(in);
		if (out != 1)
			close(out);
		if (!strcmp(*cmd, "cd"))
			ft_cd(cmd + 1, 1);
		else
		{
			execve(cmd[0], cmd, env);
			ft_print_err("error: cannot execute ", cmd[0], 1);
		}
	}
	// nssit had 7zaak kamal
	if (in)
		close(in);
	if (out != 1)
		close(1);
	return (pid);
}

void	pipe_handler(char **argv, char **env)
{
	int	i = 0, j;
	int	still_pipe = 1;
	int	fd[2];
	int	in, out;

	in = 0;
	while (still_pipe)
	{
		char	*cmd[500];
		j = 0;
		// don t forget this :
		out = 1;
		while (argv[i] || strcmp(argv[i], "|"))
		{
			cmd[j] = argv[i];
			i++;
			j++;
		}
		cmd[j] = NULL;
		still_pipe = 0;
		if (argv[i])
		{
			i++;
			still_pipe = 1;
			pipe(fd);
			out = fd[1];
		}
		// if (!strcmp(cmd[0], "cd"))
		// 	ft_cd(cmd + 1, 0);
		// else
		int pid = cmd_handler(cmd, env, in, out);
		//nsiti hdi
		waitpid(pid, NULL, 0);
		in = fd[0];
	}
}

void	comma_handler(char **argv, char **env)
{
	int	i = 0, j;
	int	still_comma = 1;

	while(still_comma)
	{
		char	*cmd[500];
		j = 0;
		while (argv[i] && strcmp(argv[i], ";"))
		{
			cmd[j] = argv[i];
			i++;
			j++;
		}
		cmd[j] = NULL;
		still_comma = 0;
		if (argv[i])
		{
			i++;
			still_comma = 1;
		}
		// I missed this part :
		if (cmd[0])
		{
			if (strcmp(cmd[0], "cd"))
				ft_cd(cmd + 1, 0);
			else
				pipe_handler(argv, env);
		}
	}
}

int	main(int ac, char **argv, char **env)
{
	 
}