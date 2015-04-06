/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:05:22 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/06 16:24:29 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**st_getlast(char **env)
{
	if (!*env)
		return (env);
	while (*(env + 1))
		env++;
	return (env);
}

int			bi_unsetenv(char **env, char *var)
{
	char	**last;

	if (!*env || !var || !*var)
		return (-1);
	var++;
	last = st_getlast(env);
	env = getenv_p(env, var);
	if (env)
	{
		free(*env);
		*env = *last;
		*last = NULL;
		return (0);
	}
	ft_putendl("Variable does not exist");
	return (-1);
}
