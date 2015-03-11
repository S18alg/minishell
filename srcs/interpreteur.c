/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreteur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:34:05 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/11 17:59:23 by sle-guil         ###   ########.fr       */
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
	return (ret);
}

int		interpreter(char **env)
{
	char	*line;
	char	**command;
	char	**tmp;
	int		ret;

	ret = 1;
	line = NULL;
	if ((ret = get_next_line(0, &line)) > 0)
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
