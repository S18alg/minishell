/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:03:01 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/18 18:45:39 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	st_setenv(char const *s, char **env)
{
	int		ow;

	ow = 0;
	s = ft_strchr(s, ' ');
	if (!s)
		return (-1);
	s++;
	if (*s == '-')
	{
		ow = (*(s + 1) == 'i') ? 1 : 0;
		if (!ow)
		{
			ft_putendl_fd("setenv : incorrect arg, use -i to overwrite", 2);
			return (-1);
		}
		s += 3;
	}
	return (bi_setenv(env, s, ow));
}

int			builtins(char const *cmd, char **env)
{
	if (!ft_strncmp(cmd, "exit", 4))
		bi_exit(cmd + 5);
	else if (!ft_strncmp(cmd, "env", 3))
		bi_env(env, ft_strchr(cmd, ' '));
	else if (!ft_strncmp(cmd, "setenv", 6))
		return (st_setenv(cmd, env));
	else if (!ft_strncmp(cmd, "unsetenv", 8))
		return (bi_unsetenv(env, ft_strchr(cmd, ' ') + 1));
	/*else if (!ft_strncmp(cmd, "cd", 2))
		bi_cd(env, cmd);*/
	return (1);
}
