/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreteur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:34:05 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/18 15:19:49 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 *	@name : interpreter
 *	@brief: This function get a commande typed by the user and execute it
 */

static int	st_isbuiltins(char const *cmd)
{
	int		ret;

	ret = 0;
	if (!ft_strncmp(cmd, "exit", 4))
		ret = 1;
	if (!ft_strncmp(cmd, "env", 3))
		ret = 1;
	if (!ft_strncmp(cmd, "setenv", 6))
		ret = 1;
	if (!ft_strncmp(cmd, "unsetenv", 8))
		ret = 1;
	if (!ft_strncmp(cmd, "history", 7))
		ret = 1;
	return (ret);
}

int			interpreter(char **env, int fd)
{
	char	*line;
	char	**command;
	char	**tmp;
	int		ret;

	line = NULL;
	if ((ret = get_next_line(fd, &line)) > 0)
	{
		command = parse(line);
		history(line, H_SAVE);
		tmp = command;
		while (command && *command)
		{
			if (st_isbuiltins(*command))
				builtins(*command, env);
			else
				runcmd(*command, env);
			free(*command);
			command++;
		}
		free(tmp);
	}
	return (ret);
}
