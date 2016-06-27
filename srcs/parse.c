/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:45:50 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/24 16:09:53 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_iter(char *s)
{
	while (*s)
	{
		*s = *(s + 1);
		s++;
	}
}

static void	st_delspace(char *s)
{
	while (*s)
	{
		if (*s == '\t' || *s == '\n')
			*s = ' ';
		if (ft_isspace(*s) && (ft_isspace(*(s + 1)) || !*(s + 1)))
			st_iter(s);
		else if (*s == ';' && ft_isspace(*(s + 1)))
			st_iter(s + 1);
		else
			s++;
	}
}

char		**parse(char *cmd)
{
	char	**new;
	char	*tmp;

	while (*cmd && ft_isspace(*cmd))
		cmd++;
	tmp = ft_strdup(cmd);
	st_delspace(tmp);
	new = ft_strsplit(tmp, ';');
	free(tmp);
	return (new);
}
