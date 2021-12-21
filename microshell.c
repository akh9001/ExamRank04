/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:19:18 by akhalidy          #+#    #+#             */
/*   Updated: 2021/12/21 19:43:29 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

typedef struct s_data
{
	int		in;
	int		out;
	int		fd[2];
	bool	pipe;
	char	**cmd;
} t_data;

int		cmdlen(t_data *line_cmd, char **argv, int *pos)
{
	int	i;
	int	index;

	i = 0;
	if (line_cmd->pipe)
		line_cmd->in = line_cmd->out;
	while (argv[*pos] && !strncmp(argv[*pos], ";", 1))
		(*pos)++;
	index = *pos;
	while (argv[index] && strncmp(argv[index], ";", 1))
	{
		if (!strncmp(argv[index], "|", 1))
		{
			line_cmd->pipe = true;
			return (i);
		}
		index++;
		i++;
	}
	return (i);
}

void	ft_initialize(t_data *line_cmd, char **argv, int *pos)
{
	int	len;
	int	i;

	i = 0;
	len = cmdlen(line_cmd, argv, pos);
	// if (!len)
	// 	return;
	free(line_cmd->cmd);
	line_cmd->cmd = malloc(sizeof(line_cmd) * (len + 1));
	//what if we have "arg;" ??
	while (i < len)
	{
		line_cmd->cmd[i] = argv[*pos];
		i++;
		(*pos)++;
	}
	line_cmd->cmd[i] = NULL;
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return(i);
}

void	ft_print_err(char *err, char *cmd)
{
	// "error: cannot execute executable_that_failed"
	write(2, err, ft_strlen(err));
	write(2, cmd, ft_strlen(cmd));
	
}

void	ft_execute(t_data *line_cmd, char **envp)
{
	if (line_cmd->pipe)
	{
		pipe(line_cmd->fd);
		line_cmd->out = line_cmd->fd[1];
		
	}
	// set ios :
	int id;
	int	status;
	
	id = fork();
	if (!id)
	{
		dup2(line_cmd->in, 0);
		dup2(line_cmd->out, 1);
		if (line_cmd->fd[0] != -1)
			close (line_cmd->fd[0]);
		if (line_cmd->fd[1] != -1)
			close (line_cmd->fd[1]);
		if (line_cmd->in != 0)
			close(line_cmd->in);
		// printf("\033[37m|%s|\n\033[0m", line_cmd->cmd[1]);
	// printf("\033[32mthis shouldn't appear!\n\033[0m");
		execve(line_cmd->cmd[0], line_cmd->cmd, envp);
		ft_print_err("error: cannot execute ", line_cmd->cmd[0]);
	}
	waitpid(id, &status, 0);
	close(line_cmd->fd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	line_cmd;
	int		pos;

	pos = 1;
	line_cmd.cmd = NULL;
	line_cmd.in = 0;
	line_cmd.out = 1;
	line_cmd.fd[0] = -1;
	line_cmd.fd[1] = -1;
	line_cmd.pipe = false;
	while(pos < argc)
	{
		ft_initialize(&line_cmd, argv, &pos);
		if (line_cmd.cmd[0])
			ft_execute(&line_cmd, envp);
	}
	return (0);
}
	// printf("\033[32mthis shouldn't appear!\n\033[0m");
	// printf("\033[37m|%s|\n\033[0m", argv[pos]);