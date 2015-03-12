/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 16:25:34 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/12 16:00:13 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		testpath(char const *path)
{
	int		ret;

	ret = (access(path, F_OK) != -1) ? 1 : 0;
	ret += (access(path, X_OK) != -1) ? 8 : 0;
	return (ret);
}
