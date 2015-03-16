/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 15:47:56 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/16 17:23:32 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	char	**loc_env;
	int		i;

	(void)av;
	loc_env = env_cp(env);
	i = 1;
	if (ac == 1)
	{
		print_prompt(loc_env);
		while (interpreter(loc_env) > 0)
			print_prompt(loc_env);
	}
	else
	{
		while (i < ac)
			i++;
			// script(av[i++], loc_env, env);
	}
	return (0);
}
