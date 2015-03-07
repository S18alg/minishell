/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:35:49 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/07 14:57:42 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 *	name : runcmd
 *	brief : This function run the cmd into fork after getting the rigth path
 */

//	Testing function...
static char	**st_initopt(char const *cmd, char **env)
{
	char **new;

	(void)env;
	new = malloc(sizeof(char*) * 4);
	*new = ft_strjoin("/bin/", cmd);
	*(new + 1) = ft_strdup("-la");
	*(new + 2) = NULL;
	return (new);
}

static void	st_free(char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void		runcmd(char const *cmd, char **env)
{
	char	**opt;
	pid_t	father;

	father = fork();
	if (!father)
	{
		opt = st_initopt(cmd, env);
		execve(*opt, opt, NULL);
		st_free(opt);
	}
	else
		wait(NULL);
}
