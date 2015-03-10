/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:35:49 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/10 14:45:30 by sle-guil         ###   ########.fr       */
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

	if (!dirpath)
		return (NULL);
	// Need to manage "string"
	path = get_pathcmd(cmd, dirpath);
	new = ft_strsplit(cmd, ' ');
	free(dirpath);
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

// Thing to add here...
// alias come here
// ~ = Home
// Better do a function...
void		runcmd(char const *cmd, char **env)
{
	char	**opt;
	char	*path;
	pid_t	father;

	opt = st_initopt(cmd, env_getpath(env));
	father = fork();
	if (!father)
		if (opt)
			execve(*opt, opt, env);
		else
			er_notfound(cmd);
	else
	{
		wait(NULL);
		st_free(opt);
	}
}
