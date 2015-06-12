/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_testbin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/16 15:14:47 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/16 15:15:34 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new.h"

int		exe_testbin(char const *bin)
{
	int			ret;
	struct stat	info;

	ret = (access(bin, F_OK) != -1) ? 1 : 0;
	ret += (access(bin, X_OK) != -1) ? 8 : 0;
	if (ret)
	{
		lstat(bin, &info);
		if (info.st_mode == S_IFDIR)
			ret *= (-1);
	}
	return (ret);
}
