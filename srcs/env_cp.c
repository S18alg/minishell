/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 12:24:29 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/09 18:56:50 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	st_len(char **env)
{
	size_t	ret;

	ret = 0;
	while (env + ret && env[ret])
		ret++;
	return (ret + 1);
}

char			**env_cp(char **env)
{
	char	**new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(char*) * st_len(env));
	while (env + i && env[i])
	{
		new[i] = ft_strdup(env[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
