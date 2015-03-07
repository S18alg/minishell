/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/07 12:24:29 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/07 13:15:45 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	st_len(char **len)
{
	size_t	ret;

	ret = 0;
	while (len && *len)
	{
		len++;
		ret++;
	}
	return (ret);
}

char			**copy_env(char **env)
{
	char	**new;
	size_t	i;

	i = 0;
	new = malloc(sizeof(char*) * st_len(env) + 1);
	while (env + i && env[i])
	{
		new[i] = ft_strdup(env[i]);
		i++;
	}
	new[i] = NULL;
	return (new);
}
