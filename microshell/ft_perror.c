/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:56:03 by merlich           #+#    #+#             */
/*   Updated: 2022/06/06 19:10:38 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_print_error_fatal(void)
{
	write(2, "error: fatal\n", 13);
	exit(1);
}

void	ft_print_execve_fail(char *cmd)
{
	write(2, "error: cannot execute ", 22);
	write(2, cmd, ft_strlen(cmd));
	write(2, "\n", 1);
}
