/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:57:15 by merlich           #+#    #+#             */
/*   Updated: 2022/06/06 19:23:57 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_cd(char **cmd_line)
{
	int	i;
	int	stat;

	i = 0;
	stat = 0;
	while (cmd_line[i])
		i++;
	if (i > 2)
	{
		write(2, "error: cd: bad arguments\n", 25);
		stat = 1;
	}
	else
	{
		if (chdir(cmd_line[1]))
		{
			write(2, "error: cd: cannot change directory to ", 38);
			write(2, cmd_line[1], ft_strlen(cmd_line[1]));
			write(2, "\n", 1);
			stat = 1;
		}	
	}
	return (stat);
}
