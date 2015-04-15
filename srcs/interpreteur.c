/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreteur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:34:05 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/15 15:47:36 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 *	@name : interpreter
 *	@brief: This function get a commande typed by the user and execute it
 */
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
			runcmd(*command, env);
			command++;
		}
		ft_freesplit(tmp);
	}
	return (ret);
}
