/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 18:31:27 by merlich           #+#    #+#             */
/*   Updated: 2022/06/06 19:00:43 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "microshell.h"

// t_cmds	*ft_lstnew(void)
// {
// 	t_cmds	*new;
	
// 	new = malloc(sizeof(t_cmds));
// 	if (new)
// 	{
// 		new->semicolon = 0;
// 		pipe(new->pipe);
// 		new->cmd = NULL;
// 		new->cmds_argv = NULL;
// 		new->next = NULL;
// 	}
// 	return (new);
// }

// void	ft_lstadd_front(t_cmds **head, t_cmds *new)
// {
// 	if (new)
// 	{
// 		new->next = *head;	
// 		*head = new;
// 	}
// }

// t_cmds	*ft_lstlast(t_cmds *head)
// {
// 	while (head->next)
// 	{
// 		head = head->next;
// 	}
// 	return (head);
// }

// void	ft_lstadd_back(t_cmds **head, t_cmds *new)
// {
// 	t_cmds *last;

// 	if (new)
// 	{
// 		if (*head == NULL)
// 		{
// 			ft_lstadd_front(head, new);
// 		}
// 		else
// 		{
// 			last = ft_lstlast(*head);
// 			last->next = new;
// 			new->next = NULL;
// 		}
// 	}
// }

// void	ft_lstdelone(t_cmds *node)
// {
// 	if (node)
// 	{
// 		free(node->cmd);
// 		free(node->cmds_argv);
// 		close(node->pipe[0]);
// 		close(node->pipe[1]);
// 		free(node);
// 	}
// }

// void	ft_lstclear(t_cmds **head)
// {
// 	t_cmds	*tmp;

// 	tmp = *head;
// 	while (tmp)
// 	{
// 		ft_lstdelone(tmp);
// 		*head = (*head)->next;
// 	}
// }
