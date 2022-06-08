/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:44:08 by merlich           #+#    #+#             */
/*   Updated: 2022/06/08 21:36:05 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		k;
	int		cmds_num;
	int		p1[2];
	int		p2[2];
	char	**cmd_line;
	int		m;
	// int		count;

	i = 1;
	k = 0;
	// count = 0;
	cmds_num = ft_count_cmds(argv);
	printf("cmds_num = %d\n", cmds_num);
	if (cmds_num)
	{
		while (argv[i])
		{
			cmd_line = ft_build_cmd_line(argv, &i);
			// if (count)
			// {
			if (!strcmp(cmd_line[0], "cd"))
				ft_cd(cmd_line);
			// if (pipe(p1))
			// 	ft_print_error_fatal();
			ft_exec_many_cmds(p1, p2, cmd_line, k, cmds_num, envp);
			k++;
			if (!strcmp(argv[i - 1], ";"))
			{
				cmds_num -= k;
				printf("cmds_num = %d\n", cmds_num);
				k = 0;
			}
			// }
			// count++;
			m = 0;
			while (cmd_line[m])
			{
				printf("cmd_line[%d] = %s\n", m, cmd_line[m]);
				m++;
			}
			free(cmd_line);
		}
		k = -1;
		while (++k < cmds_num - 1)
			waitpid(-1, NULL, 0);
	}
	return (0);
}
