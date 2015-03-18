/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 18:05:22 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/18 16:47:21 by sle-guil         ###   ########.fr       */
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
	int		len;

	if (!*env)
		return (-1);
	len = ft_strlen(var);
	last = st_getlast(env);
	while (ft_strncmp(*env, var, len))
		env++;
	free(*env);
	*env = *last;
	*last = NULL;
	return (0);
}
