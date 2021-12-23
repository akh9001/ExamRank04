/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:19:18 by akhalidy          #+#    #+#             */
/*   Updated: 2021/12/23 16:47:56 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		printf("in = %d, out = %d\n", in, out);
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
		out = 1;
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
	(void)ac;
	handle_comma(av + 1);
}