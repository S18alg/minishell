/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_alias.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 19:45:01 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/06 20:29:52 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_print(t_list *lst)
{
	while (lst)
	{
		ft_putstr((t_alias*)(lst->content)->name);
		ft_putstr("=");
		ft_putendl((t_alias*)(lst->content)->value);
		lst = lst->next;
	}
}

static void	st_del(void	*content, size_t size)
{
	t_alias	*p;

	p = content;
	(void)size;
	free(p);
}

static void	st_seek(t_list **lst, char *name)
{
	void	(*f)(void *, size_t);

	f = st_del;
	while (*lst)
	{
		if (!ft_strcmp((t_alias)((*lst)->content)->name, name))
		{
			ft_lstdelone(lst, f);
			break ;
		}
		*lst = (*lst)->next;
	}
}

t_list		*manage_alias(char *value[2], int action)
{
	static t_list	*alias = NULL;
	t_alias			*new;

	if (!value)
		return (alias);
	if (action == AL_ADD)
	{
		new = malloc(sizeof(t_alias));
		new.name = value[0];
		new.value = value[1];
		ft_lstadd(&alias, ft_lstnew(new, sizeof(t_alias)));
	}
	else if (action == AL_PRIN)
		st_print(alias);
	else
		st_seek(&alias, *value);
	return (NULL);
}
