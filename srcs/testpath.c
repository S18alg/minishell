/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 16:25:34 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/15 15:42:36 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		testpath(char const *path)
{
	int			ret;
	struct stat	info;

	ret = (access(path, F_OK) != -1) ? 1 : 0;
	ret += (access(path, X_OK) != -1) ? 8 : 0;
	if (ret)
	{
		lstat(path, &info);
		if (info.st_mode == S_IFDIR)
			ret *= (-1);
	}
	return (ret);
}
