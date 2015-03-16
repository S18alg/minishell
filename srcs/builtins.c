/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:03:01 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/16 17:20:13 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtins(char const *cmd, char **env)
{
	if (!ft_strncmp(cmd, "exit", 4))
		bi_exit(cmd + 5);
	else if (!ft_strncmp(cmd, "env", 3))
		bi_env(env);
	else if (!ft_strncmp(cmd, "unsetenv", 8))
		bi_unsetenv(env, ft_strchr(cmd, ' ') + 1);
	/*else if (!ft_strncmp(cmd, "cd", 2))
		bi_cd(env, cmd);*/
	return (1);
}
