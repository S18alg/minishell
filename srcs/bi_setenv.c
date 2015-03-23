/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 17:27:50 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/23 14:38:19 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*st_init(char const *s)
{
	char	*new;
	char	*tmp;

	new = ft_strdup(s);
	tmp = ft_strchr(new, ' ');
	if (!tmp || tmp != ft_strrchr(new, ' ') || ft_strchr(new, '='))
	{
		if (ft_strchr(new, '='))
			ft_putendl_fd("Error : Do not use \'=\' to setenv", 2);
		else if (tmp != ft_strrchr(new, ' '))
			ft_putendl_fd("setenv : incorrect number of arg", 2);
		free(new);
		return (NULL);
	}
	*tmp = '=';
	return (new);
}

int			bi_setenv(char **env, char const *var, int overwrite)
{
	char	*new;
	int		len;
	int		i;

	i = 0;
	if (!var || !(*var) || !(new = st_init(var)))
		return (-1);
	len = ft_strlen_unt_c(new, '=');
	while (env[i] && ft_strncmp(new, env[i], len))
		i++;
	if (env[i])
	{
		if (overwrite)
			free(env[i]);
		else
		{
			free(new);
			ft_putendl_fd("Value already exist, use -i to over write", 2);
			return (-1);
		}
	}
	env[i] = new;
	return (0);
}
