/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:35:49 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/14 16:42:36 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 *	@name:	runcmd
 *	@brief:	This function run the cmd into fork after getting the rigth path
 *
 *	Note about "..." management :
 *		I could manage this type of argument by spliting the " caracter
 *		and then subsplit odd number with ' '
 */
static char	**st_initopt(char const *cmd, char *dirpath)
{
	char	**new;
	char	*path;

	new = ft_strsplit(cmd, ' ');
	if (testpath(*new) >= 8)
	{
		free(dirpath);
		return (new);
	}
	if (!dirpath)
		return (NULL);
	path = parse_path(dirpath, cmd);
	free(dirpath);
	if (path)
	{
		free(*new);
		*new = path;
	}
	else
	{
		ft_freesplit(new);
		new = NULL;
	}
	return (new);
}

static void	st_upenv(char *cmd, char **env)
{
	env = getenv_p(env, "_=");
	if (*env)
		free(*env);
	*env = ft_strjoin("_=", cmd);
}

void		runcmd(char const *cmd, char **env)
{
	char	**opt;
	pid_t	father;

	opt = st_initopt(cmd, getenv_cpy(env, "PATH"));
	father = fork();
	if (!father)
	{
		signal(SIGINT, SIG_DFL);
		if (opt)
			execve(*opt, opt, env);
		er_notfound(cmd);
	}
	else
	{
		if (opt)
			st_upenv(*opt, env);
		wait(NULL);
		ft_freesplit(opt);
	}
}
