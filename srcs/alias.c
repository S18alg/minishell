/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 19:21:33 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/06 20:00:41 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell"

/*!
 *		Alias
 *	@name:		alias
 *	@brief:		Manage alias for minishell
 */
char	*alias(char *cmd)
{
	t_list		*alias;
	char		**tmp;

	alias = manage_alias(NULL, 0);
	while (alias)
	{
		if (ft_strstr(cmd, (t_alias*)(alias->content)->name))
		{
			tmp = ft_strsplit_pat(cmd, (t_alias*)(alias->content)->value);
			free(cmd);
			cmd = ft_strjoin_pat(tmp, (t_alias*)(alias->content)->value);
			ft_freesplit(tmp);
		}
		alias = alias->next;
	}
	return (cmd);
}
