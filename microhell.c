/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microhell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:30:35 by akhalidy          #+#    #+#             */
/*   Updated: 2022/02/11 19:37:16 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return(i);
}

void	ft_cd(char **path)
{
	if ()
}