/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 15:47:56 by sle-guil          #+#    #+#             */
/*   Updated: 2015/02/25 14:19:39 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int ac, char **av, char **env)
{
	int		i;

	(void)av;
	i = 1;
	if (ac == 1)
	{
		print_prompt();
		while (interpreter(env) > 0)
			print_prompt();
	}
	else
	{
		while (i < ac)
			i++;
			// script(av[i++]);
	}
	return (0);
}
