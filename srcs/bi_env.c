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

static int	st_over(char const *s)
{
	if (!s)
		return (0);
	if (s[0] == '-')
	{
		if (s[1] == 'i' && (!s[2] || s[2] == ' '))
			return (1);
		else
		{
			ft_putendl("incorrect use of env : us -i to ignor current env.");
			return (-1);
		}
	}
	return (0);
}

static char const	*st_init(char ***env, char const *cmd)
{
	char	*tmp;
	char	*c;
	
	while (cmd && ft_strchr(cmd, '=') && (tmp = ft_strcdup(cmd, ' ')))
	{
		if ((c = ft_strchr(tmp, '=')))
		{
			*c = ' ';
			bi_setenv(*env, tmp, 1);
			*env = env_refresh(*env);
		}
		free(tmp);
		cmd = (ft_strchr(cmd, ' ')) ? ft_strchr(cmd, ' ') + 1 : NULL;
	}
	return (cmd);
}

int			bi_env(char **env, char const *arg)
{
	char const	*cmd;
	int			ret;

	if (arg)
		arg++;
	if ((ret = st_over(arg)) > 0)
	{
		env = env_cp(NULL);
		arg = (ft_strchr(arg, ' ')) ? ft_strchr(arg, ' ') + 1 : NULL;
	}
	else if (!ret)
		env = env_cp(env);
	else
		return (-1);
	cmd = st_init(&env, arg);
	if (!cmd)
		st_print(env);
	else
		runcmd(cmd, env);
	env_free(env);
	return (0);
}
