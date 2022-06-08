/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:59:07 by merlich           #+#    #+#             */
/*   Updated: 2022/06/08 21:29:19 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
	}
	return (len);
}

int	ft_count_cmds(char **str)
{
	int	i;
	int	num;

	i = 1;
	num = 1;
	// if (str[1])
	// {
		// num = 1;
		while (str[i])
		{
			if (!strcmp(str[i], "|") || !strcmp(str[i], ";"))
				num++;
			i++;
		}
	// }
	return (num);
}

char	**ft_build_cmd_line(char **argv, int *i)
{
	int		j;
	int		len;
	char	**line;

	j = 0;
	len = 0;
	line = NULL;
	while (argv[*i + len] && strcmp(argv[*i + len], "|") && strcmp(argv[*i + len], ";"))
		len++;
	// printf("len = %d\n", len);
	line = malloc(sizeof(char *) * (len + 1));
	if (NULL == line)
		ft_print_error_fatal();
	while (j < len)
	{
		line[j] = argv[*i + j];
		// printf("cmd_line = %s\n", line[j]);
		j++;
	}
	line[j] = NULL;
	*i += len;
	if (argv[*i])
		*i = *i + 1;
	return (line);
}
