/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpath.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 16:25:34 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/11 16:48:51 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		testpath(char *path)
{
	int		ret;

	ft_putendl("boobs");
	ret = (access(path, F_OK)) ? 1 : 0;
	ret += (access(path, R_OK)) ? 2 : 0;
	ret += (access(path, W_OK)) ? 4 : 0;
	ret += (access(path, X_OK)) ? 8 : 0;
	return (ret);
}
