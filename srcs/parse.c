/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:45:50 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/11 17:39:50 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *	@name:	command parser
 *	@brief:	First parser to apply on the user input, del useless space
 *			and split each sub commande ';'
 */

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
