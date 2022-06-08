#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <string.h>

/* ft_cd.c */
int		ft_cd(char **cmd_line);

/* ft_perror.c */
int		ft_print_error_fatal(void);
void	ft_print_execve_fail(char *cmd);

/* microshell_utils.c */
int		ft_strlen(char *s);
int		ft_count_cmds(char **str);
char	**ft_build_cmd_line(char **argv, int *i);

/* exec_cmds.c */
void	ft_exec_one_cmd(char **cmd_line, char **envp);
void	ft_exec_many_cmds(int p1[2], int p2[2], char **cmd_line, int k, int cmds_num, char **envp);

#endif