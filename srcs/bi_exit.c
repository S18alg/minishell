/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 14:48:23 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/14 14:49:33 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_exit(char const *arg)
{
	int		ret;

	ret = 0;
	while (arg[ret] && ft_isdigit(arg[ret]))
		ret++;
	if (arg[ret])
	{
		if (ft_isspace(arg[ret]))
			ft_putendl("exit error : Too many argument");
		else
			ft_putendl("exit error : unexpected character");
		return ;
	}
	ret = ft_atoi(arg);
	exit((char)ret);
}
