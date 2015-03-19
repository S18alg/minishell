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
static char	**st_initenv(char **env, char const *arg)
{
	char	**new;

	if (*arg == '-')
	{
		if (*(arg + 1) == 'i')
		{
			new = malloc (sizeof(char*) * 2);
			*new = ft_strdup(ft_strchr(arg, ' ') + 1);
			*(new + 1) = NULL;
			return (new);
		}
		else
		{
			ft_putendl("env: Incorrect option. use -i to ignore env");
			return (NULL);
		}
	}
	else
		return (env_cp(env));
}

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
	//char	*cmd;
	int		ret;

	ret = 0;
	(void)arg;
	if (!(env = st_initenv(env, arg)))
		return (-1);
	st_print(env);
	env_free(env);
	return (ret);
}
