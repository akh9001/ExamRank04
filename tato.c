/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tato.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:15:28 by akhalidy          #+#    #+#             */
/*   Updated: 2022/02/11 12:33:10 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	ft_strlen(char *str)
{
	int	i = 0;
	
	while(str[i])
		i++;
	return (i);
}

void	ft_print_error(char *err, char *cmd, int ext)
{
	write(2, err, ft_strlen(err));
	if (cmd)
		write(2, cmd, ft_strlen(err));
	write(2, "\n", 1);
	if (ext)
		exit(1);
}