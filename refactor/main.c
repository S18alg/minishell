/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 15:47:56 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/16 15:25:43 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

static void	st_upenv(char **env)
{
	char	**tmp;
	char	*val;

	tmp = getenv_p(env, "SHLVL=");
	if (tmp)
		(*tmp)[6]++;
	val = getenv_cpy(env, "_=");
	tmp = getenv_p(env, "SHELL=");
	if (tmp && val)
	{
		free(*tmp);
		*tmp = ft_strjoin("SHELL=", val);
	}
	if (val)
		free(val);
}

int			main(int ac, char **av, char **env)
{
	char	**loc_env;
	int		i;

	i = 1;
	signal(SIGINT, SIG_IGN);
	loc_env = env_cp(env);
	st_upenv(loc_env);
	if (ac == 1)
	{
		print_prompt(env);
		while (interpreter(loc_env, 0) > 0)
		{
			loc_env = env_refresh(loc_env);
			print_prompt(loc_env);
		}
	}
	else
	{
		while (i < ac)
			loc_env = script(av[i++], loc_env);
	}
	return (0);
}
