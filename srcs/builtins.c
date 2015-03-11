/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:03:01 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/11 17:19:03 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtins(char const *cmd, char **env)
{
	(void)env;
	if (!ft_strncmp(cmd, "exit", 4))
		exit(0);
	else if (!ft_strncmp(cmd, "env", 3))
		bi_env(env);
	/*else if (!ft_strncmp(cmd, "cd", 2))
		bi_cd(env, cmd);*/
	return (1);
}
