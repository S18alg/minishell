/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_cp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 12:24:29 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/24 16:08:50 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	st_len(char **env)
{
	size_t	ret;

	ret = 0;
	while (env && env[ret])
		ret++;
	return (ret + 2);
}

char			**env_cp(char **env)
{
	char	**new;
	int		i;

	i = 0;
	new = malloc(sizeof(char *) * st_len(env));
	while (env && env[i])
	{
		new[i] = ft_strdup(env[i]);
		i++;
	}
	new[i] = NULL;
	new[i + 1] = NULL;
	return (new);
}
