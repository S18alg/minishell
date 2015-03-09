/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_getpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 18:58:06 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/09 19:11:36 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*env_getpath(char const **env)
{
	char	*new;

	while (env && *env)
	{
		if (ft_strncmp(*env, "PATH=", 5))
		{
			new = (char const *)ft_strchr(*env, '=');
			new = ft_strdup(new + 1);
			return (new);
		}
		env++;
	}
	return (NULL);
}
