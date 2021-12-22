/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:19:18 by akhalidy          #+#    #+#             */
/*   Updated: 2021/12/22 14:12:40 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>
// #include <stdbool.h>
// #include <string.h>
// #include <unistd.h>

// typedef struct s_data
// {
// 	int		in;
// 	int		out;
// 	int		fd[2];
// 	bool	pipe;
// 	char	**cmd;
// } t_data;

// int		cmdlen(t_data *line_cmd, char **argv, int *pos)
// {
// 	int	i;
// 	int	index;

// 	i = 0;
// 	if (line_cmd->pipe)
// 	{
// 		line_cmd->in = line_cmd->out;
// 		line_cmd->out = 1;
// 		line_cmd->fd[0] = -1;
// 		line_cmd->fd[1] = -1;
// 		line_cmd->pipe = false;
// 	}
// 	// printf("\033[37miiin|%d|\n\033[0m", line_cmd->in);
// 	while (argv[*pos] && (!strncmp(argv[*pos], ";", 1) || !strncmp(argv[*pos], "|", 1)))
// 	{
// 		// printf("####%d\n", *pos);
// 		(*pos)++;
// 	}
// 	index = *pos;
// 	while (argv[index] && strncmp(argv[index], ";", 1))
// 	{
// 		if (!strncmp(argv[index], "|", 1))
// 		{
// 			line_cmd->pipe = true;
// 			return (i);
// 		}
// 		index++;
// 		i++;
// 	}
// 	return (i);
// }

// void	ft_initialize(t_data *line_cmd, char **argv, int *pos)
// {
// 	int	len;
// 	int	i;

// 	i = 0;
// 	len = cmdlen(line_cmd, argv, pos);
// 	// if (!len)
// 	// 	return;
// 	free(line_cmd->cmd);
// 	line_cmd->cmd = malloc(sizeof(line_cmd) * (len + 1));
// 	//what if we have "arg;" ??
// 	while (i < len)
// 	{
// 		line_cmd->cmd[i] = argv[*pos];
// 		i++;
// 		(*pos)++;
// 	}
// 	line_cmd->cmd[i] = NULL;
// }

// int		ft_strlen(char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return(i);
// }

// void	ft_print_err(char *err, char *cmd)
// {
// 	// "error: cannot execute executable_that_failed"
// 	write(2, err, ft_strlen(err));
// 	write(2, cmd, ft_strlen(cmd));
	
// }

// void	ft_execute(t_data *line_cmd, char **envp)
// {
// 	if (line_cmd->pipe)
// 	{
// 		pipe(line_cmd->fd);
// 		line_cmd->out = line_cmd->fd[0];
		
// 	}
// 	// set ios :
// 	int id;
// 	int	status;
	
// 	printf("\033[32mthis shouldn't appear %d, %d, %d, %d, %s, pipe flag %d!\n\033[0m",
// 	line_cmd->in, line_cmd->out, line_cmd->fd[0], line_cmd->fd[1], line_cmd->cmd[0], line_cmd->pipe);
// 	id = fork();
// 	if (!id)
// 	{
// 		dup2(line_cmd->in, 0);
// 		dup2(line_cmd->out, 1);
// 		// fprintf(stderr,"\033[37m 1 - |%d|, |%d|\n\033[0m", line_cmd->in, line_cmd->out);
// 		// fprintf(stderr,"\033[37m 1 - |%d|, |%d|\n\033[0m", line_cmd->fd[0], line_cmd->fd[1]);
// 		// printf("\033[32mthis shouldn't appear!\n\033[0m");
// 		// printf("\033[37m|%s|\n\033[0m", line_cmd->cmd[0]);
// 		// printf("\033[37m|%d|, |%d|\n\033[0m", line_cmd->fd[0], line_cmd->fd[1]);
// 		// fprintf(stderr,"\033[37m |%d|, |%d|\n\033[0m", line_cmd->in, line_cmd->out);
// 		if (line_cmd->fd[0] != -1)
// 			close (line_cmd->fd[0]);
// 		if (line_cmd->fd[1] != -1)
// 			close (line_cmd->fd[1]);
// 		if (line_cmd->in != 0)
// 			close(line_cmd->in);
// 		// printf("\033[37m|%s|\n\033[0m", line_cmd->cmd[1]);
// 	// printf("\033[32mthis shouldn't appear!\n\033[0m");
// 		execve(line_cmd->cmd[0], line_cmd->cmd, envp);
// 		ft_print_err("error: cannot execute ", line_cmd->cmd[0]);
// 	}
// 	waitpid(id, &status, 0);
// 	close(line_cmd->fd[1]);
// 	// close(line_cmd->fd[1]);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	t_data	line_cmd;
// 	int		pos;

// 	pos = 1;
// 	line_cmd.cmd = NULL;
// 	line_cmd.in = 0;
// 	line_cmd.out = 1;
// 	line_cmd.fd[0] = -1;
// 	line_cmd.fd[1] = -1;
// 	line_cmd.pipe = false;
// 	while(pos < argc)
// 	{
// 		ft_initialize(&line_cmd, argv, &pos);
// 		// printf("n = %d l= %d\n", pos, argc);

// 		if (line_cmd.cmd[0])
// 		{
// 			ft_execute(&line_cmd, envp);
// 		}
// 	}
// 	return (0);
// }
// 	// printf("\033[32mthis shouldn't appear!\n\033[0m");
// 	// printf("\033[37m|%s|\n\033[0m", argv[pos]);
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


void handle_cmd(char **cmd, int in, int out)
{
	int pid;
	pid = fork();
	if (!pid)
	{
		dup2(in, 0);
		dup2(out, 1);
		if (in != 0)
			close(in);
		if (out != 1)
			close(out);
		execv(cmd[0], cmd);
		fprintf(stderr, "SOMETHING WRONG (%s)", cmd[0]);
	} else
	{
		if (in != 0)
			close(in);
		if (out != 1)
			close(out);
	}
}

void pipe_handler(char **s)
{
	// char *s[] = {"/bin/ls", ".", "|", "/usr/bin/grep", "microshell", (void *)0};
	int	still_pipe = 1;
	int i = 0;
	int in = 0;
	int out = 1;
	int fds[2];
	while (still_pipe)
	{
		char *cmd[10000];
		int j = 0;
		while (s[i] && strcmp(s[i], "|") != 0)
		{
			cmd[j] = s[i];
			i++;
			j++;
		}
		cmd[j] = (void *)0;
		still_pipe = 0;
		if (s[i])
		{
			i++;
			still_pipe = 1;
		}
		out = 1;
		if (still_pipe)
		{
			pipe(fds);
			out = fds[1];
		}
		
		handle_cmd(cmd, in, out);
		int kk;
		waitpid(-1, &kk, 0);
		in = fds[0];
	}
}

void handle_comma(char **argv)
{
	int still_comma = 1;
	int i = 0;
	while (still_comma)
	{
		char *cmd[10000];
		int j = 0;
		while (argv[i] && strcmp(argv[i], ";") != 0)
		{
			cmd[j] = argv[i];
			i++;
			j++;
		}
		cmd[j] = (void *)0;
		still_comma = 0;
		if (argv[i])
		{
			i++;
			still_comma = 1;
		}

		if (cmd[0])
			pipe_handler(cmd) ;
		
	}
}

int main(int ac, char **av)
{
	handle_comma(av + 1);
}