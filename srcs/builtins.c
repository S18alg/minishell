/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:03:01 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/12 16:43:07 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	st_exit(char const *arg)
{
	int		ret;

	ret = 0;
	while (arg[ret] && ft_isdigit(arg[ret]))
		ret++;
	if (arg[ret])
	{
		if (ft_isspace(arg[ret]))
			ft_putendl("exit error : Too many argument");
		else
			ft_putendl("exit error : unexpected character");
		return ;
	}
	ret = ft_atoi(arg);
	exit((char)ret);
}

int		builtins(char const *cmd, char **env)
{
	(void)env;
	if (!ft_strncmp(cmd, "exit", 4))
		st_exit(cmd + 5);
	else if (!ft_strncmp(cmd, "env", 3))
		bi_env(env);
	else if (!ft_strncmp(cmd, "unsetenv", 8))
		bi_unsetenv(env, ft_strchr(cmd, ' ') + 1);
	/*else if (!ft_strncmp(cmd, "cd", 2))
		bi_cd(env, cmd);*/
	return (1);
}
