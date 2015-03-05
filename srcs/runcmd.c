/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:35:49 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/05 18:40:18 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 *	name : runcmd
 *	brief : This function run the cmd into fork after getting the rigth path
 */

static char	**st_initopt()
{
	char **new;

	new = malloc(sizeof(char*) * 4);
	*new = ft_strdup("");
	*(new + 1) = ft_strdup("-la ~");
	*(new + 2) = NULL;
	*(new + 3) = NULL;
	return (new);
}

void		runcmd(char const *cmd, char **env)
{
	char	*bin;
	char	**opt;
	pid_t	father;

	(void)env;
	father = fork();
	if (father > 0)
		wait(NULL);
	else
	{
		bin = ft_strjoin("/bin/", cmd);
		opt = st_initopt();
		execve(bin, opt, NULL);
	}
}
