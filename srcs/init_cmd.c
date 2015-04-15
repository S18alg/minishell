/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/15 14:51:44 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/15 16:02:32 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 *	@name:		init_cmd
 *	@brief:		read a splited command, initialise all the path and builtins.
 */
static int	st_test_file(char **cmd)
{
	if (!(TEST_PIPE(*cmd) || TEST_STREAM(*cmd) \
				|| !TEST_PIPE((*(cmd + 1))) || !TEST_STREAM(*(cmd + 1))))
		return (0);
	return (-1);
}

static char	*st_test_exe(char *path, char *cmd)
{
	if (is_builtin(cmd) || testpath(cmd))
		return (NULL);
	return (parse_path(path, cmd));
}

int			init_cmd(char **cmd, char *path)
{
	char	*tmp;

	if (tmp = st_test_bin(*cmd))
	{
		free(*cmd);
		*cmd = tmp;
	}
	while (*cmd)
	{
		if (TEST_PIPE(*cmd) && tmp = st_test_exe(path, *(cmd + 1)))
		{
			free(*(cmd + 1));
			*(cmd + 1) = tmp;
		}
		else if (TEST_STREAM(*cmd) && !st_test_file(cmd + 1))
			return (error(STREAM_FILE_ERROR));
	}
	return (0);
}
