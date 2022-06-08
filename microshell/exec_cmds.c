/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:02:19 by merlich           #+#    #+#             */
/*   Updated: 2022/06/08 21:36:49 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

// void	ft_exec_one_cmd(char **cmd_line, char **envp)
// {
// 	pid_t	pid;
	
// 	pid = fork();
// 	if (pid < 0)
// 		ft_print_error_fatal();
// 	else if (pid == 0)
// 	{
// 		printf("%s\n", cmd_line[0]);
// 		printf("%s\n", cmd_line[1]);
// 		execve(cmd_line[0], cmd_line, envp);
// 		ft_print_execve_fail(cmd_line[0]);
// 	}
// }

static void	ft_dup2(int in, int out)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (in != 0)
		x = dup2(in, 0);
	if (out != 1)
		y = dup2(out, 1);
	if (x == -1 || y == -1)
		ft_print_error_fatal();
}

static void	ft_handle_p1(int p1[2], int p2[2],  int num_of_cmd, int last)
{
	static int	opend1 = 0;
	static int	opend2 = 0;

	if (num_of_cmd != last && num_of_cmd % 2 == 0)
	{
		if (pipe(p1))
			ft_print_error_fatal();
		opend1 = 1;
	}
	if (num_of_cmd != last && num_of_cmd % 2)
	{
		if (pipe(p2))
			ft_print_error_fatal();
		opend2 = 1;
	}
	if (num_of_cmd == 0)
		ft_dup2(0, p1[1]);
	if (num_of_cmd == last && num_of_cmd % 2)
		ft_dup2(p1[0], 1);
	else if (num_of_cmd == last && num_of_cmd % 2 == 0)
		ft_dup2(p2[0], 1);
	else if (num_of_cmd % 2)
		ft_dup2(p1[0], p2[1]);
	else if (num_of_cmd % 2 == 0)
		ft_dup2(p2[0], p1[1]);
	if (opend1)
	{
		if (close(p1[0]) || close(p1[1]))
			ft_print_error_fatal();
		opend1 = 0;
	}
	if (opend2)
	{
		if (close(p2[0]) || close(p2[1]))
			ft_print_error_fatal();
		opend2 = 0;
	}
}

void	ft_exec_many_cmds(int p1[2], int p2[2], char **cmd_line, int k, int cmds_num, char **envp)
{
	pid_t	pid;
	
	pid = fork();
	if (pid == 0)
	{
		// ft_handle_p1(p1, p2, k, cmds_num);
		execve(cmd_line[0], cmd_line, envp);
		ft_print_execve_fail(cmd_line[0]);
	}
	else if (pid < 0)
		ft_print_error_fatal();
}
