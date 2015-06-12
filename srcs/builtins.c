/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:03:01 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/16 14:28:47 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
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
*/

int			builtins(char const **cmd, char **env)
{
	/*
	else if (!ft_strncmp(cmd, "env", 3))
		bi_env(env, ft_strchr(cmd, ' '));
	else if (!ft_strncmp(cmd, "setenv", 6))
		return (st_setenv(cmd, env));
	else if (!ft_strncmp(cmd, "unsetenv", 8))
		return (bi_unsetenv(env, ft_strchr(cmd, ' ')));
	else if (!ft_strncmp(cmd, "history", 7))
		return ((int)history(NULL, H_PRINT));
	else if (!ft_strncmp(cmd, "cd", 2))
		bi_cd(env, ft_strchr(cmd, ' '));
	*/
	if (ft_strcmp(*cmd, "exit"))
		return (bi_exit(cmd));
	return (0);
}
