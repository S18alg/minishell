/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 15:44:17 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/18 09:48:05 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

static int		st_mask(t_list *lst)
{
	while (lst && !link_gettype((char *)lst->content))
		lst = lst->next;
	return (link_gettype((char*)lst->content));
}

static t_list	*st_next(t_list **lst)
{
	t_list	*tmp;

	while (lst && is_link((char*)lst->content))
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->content);
		free(tmp);
	}
	if (!lst)
		return (NULL);
	tmp = lst->next;
	free(lst->content);
	free(lst);
	return (tmp);
}

void	runcmd(char **env, char *entry)
{
	t_list	*splited;
	char	**cmd;
	int		next;

	splited = ft_strlsplit(entry, ' ');		// '...' and "..." management goes here with an big update.
	// Apply alias and regex here
	// Apply output file here
	while (splited)
	{
		cmd = forge_cmd(splited);
		next = st_mask(splited);
		wait(NULL);
		//	exec here
		ft_freesplit(cmd);
		splited = st_next(splited);
	}
}
