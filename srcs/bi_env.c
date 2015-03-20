/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 13:58:45 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/18 19:06:22 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 *	@name :		bi_env
 *	@brief :	Print the environment variables or execute a commande with custom env.
 */
static void	st_print(char **env)
{
	while (*env)
	{
		ft_putendl(*env);
		env++;
	}
}

int		bi_env(char **env, char const *arg)
{
	char	*cmd;
	char	*tmp;
	int		ret;

	ret = 0;
	cmd = (arg) ? ft_strchr(arg, ' ') + 1 : NULL;
	tmp = (arg) ? ft_strcdup(arg, ' ') : NULL;
	while (cmd && ft_strchr(cmd, '='))
		cmd = ft_strchr(cmd, ' ') + 1;
	if (!cmd)
		st_print(env);
	else
		runcmd(cmd, env);
	return (ret);
}
