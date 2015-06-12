/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 15:25:55 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/16 15:45:16 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

/**
 * @name:	Interpreter
 * @brief:	read a line on fd, store it in the history and send it to exec
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
		if (*s == '\t' || *s = '\n')
			*s = ' ';
		if (*s == ' ' && (ft_isspace(*(s + 1)) || !*(s + 1)))
			st_iter(s);
		else if (*s == ';' && ft_isspace(*(s + 1)))
			st_iter(s + 1);
		else
			s++;
	}
}

static char	**st_clean(char const *line)
{
	char	**new;
	char	* tmp;

	while (*line && ft_isspace(*line))
		line++;
	tmp = ft_strdup(cmd);
	st_delspace(tmp);
	new = ft_strsplit(tmp, ';');
	free(tmp);
	return (new);
}

int		interpreter(char **env, int fd)
{
	char	*line;
	char	**cmd;
	int		ret;
	int		i;

	line = NULL;
	i = 0;
	if (ret = get_next_line(fd, &line) > 0)
	{
		cmd = st_clean(line);
		history(line, H_SAVE);
		while (cmd[i])
			runcmd(env, cmd[i++]);
		ft_freesplit(cmd);
	}
	return (ret);
}
