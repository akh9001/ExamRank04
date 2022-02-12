/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 13:27:30 by akhalidy          #+#    #+#             */
/*   Updated: 2022/01/05 13:51:51 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_print_error(char *err, char *cmd, int ext)
{
	write(2, err, ft_strlen(err));
	if(cmd)
		write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
	if (ext)
		exit(0);
}

void	ft_cd(char **path)
{
	if (!*path || path[1])
		ft_print_error("error: cd: bad arguments", NULL, 0);
	if (chdir(*path))
		ft_print_error("error: cd: cannot change directory to ", path[0], 0);
}

void	comma_handler(char **argv, char **env)
{
	int i = 0, j;
	int still_comma = 1;

	while (still_comma)
	{
		j = 0;
		char *cmd[500];
		
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
		if (cmd[0])
		{
			
		}
	}
}