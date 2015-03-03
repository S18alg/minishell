/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreteur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:34:05 by sle-guil          #+#    #+#             */
/*   Updated: 2015/02/25 17:26:47 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 *	@name : interpreter
 *	@brief: This function get a commande typed by the user and execute it
 */

static int	st_isbuiltins(char *cmd)
{
	int		ret;

	ret = 0;
	if (!ft_strcmp(cmd, "exit"))
		ret = 1;
	return (ret);
}

int		interpreter(char **env)
{
	char	*line;
	char	*command;
	int		ret;

	(void)env;
	ret = 1;
	line = NULL;
	if ((ret = get_next_line(0, &line)) > 0)
	{
		//history(line, SAVE);
		command = parse(line);
		if (st_isbuiltins(command))
			ret = builtins(command, env);
		else
			runcmd(command, env);
	}
	return (ret);
}
