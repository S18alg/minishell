/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:35:49 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/15 16:05:02 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 *	@name:	runcmd
 *	@brief:	This function run the cmd into fork after getting the rigth path
 *
 *	Note about "..." management :
 *		I could manage this type of argument by spliting the " caracter
 *		and then subsplit odd number with ' '
 */
static void	st_upenv(char *cmd, char **env)
{
	env = getenv_p(env, "_=");
	if (*env)
	{
		free(*env);
		*env = ft_strjoin("_=", cmd);
	}
}

void		runcmd(char const *cmd, char **env)
{
	char	**exe;
	char	*path;
	pid_t	father;

	path = getenv_cpy(env, "PATH=");
	exe = init_cmd(cmd, path);
	father = fork();
	if (!father)
	{
		signal(SIGINT, SIG_DFL);
		if (exe)
			execve(*exe, exe, env);
		er_notfound(cmd);
	}
	else
	{
		if (exe)
			st_upenv(*exe, env);
		if (path)
			free(path);
		wait(NULL);
		ft_freesplit(exe);
	}
}
