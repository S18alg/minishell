/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 16:14:50 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/11 17:09:19 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * @name :		parse_path
 * @brief :		parse the PATH variable into a char** for each path.
 */

static char	*st_free(char **t, int i)
{
	char	*ret;

	ret = t[i];
	i = 0;
	while (t[i])
		free(t[i++]);
	free(t);
	return (ret);
}

char		*parse_path(char const *path, char const *cmd)
{
	char	*new;
	char	*tmp;
	char	**dir;
	int		i;

	i = 0;
	dir = ft_strsplit(path, ':');
	ft_putendl(*dir);
	tmp = ft_strcdup(cmd, ' ');
	while (dir[i])
	{
		new = ft_strjoin(dir[i], tmp);
		if (testpath(new) >= 8)
			break ;
		free(new);
		i++;
	}
	free(tmp);
	tmp = st_free(dir, i);
	if (tmp)
		return (new);
	free(new);
	return (NULL);
}
