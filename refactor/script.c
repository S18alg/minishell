/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 14:02:04 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/14 16:48:51 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**script(char const *file, char **env)
{
	int		fd;
	int		ret;
	char	**loc_env;

	ret = 1;
	if (testpath(file) < 8)
		return (env);
	fd = open(file, O_RDONLY);
	loc_env = env_cp(env);
	while (ret)
	{
		ret = interpreter(env, fd);
		loc_env = env_refresh(loc_env);
	}
	close(fd);
	ft_freesplit(env);
	return (loc_env);
}
