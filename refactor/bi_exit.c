/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 14:48:23 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/15 15:50:19 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		bi_exit(char const **arg)
{
	int		ret;

	ret = 0;
	if (*(cmd + 1))
	{
		ret = ft_atoi(arg);
		if (*(cmd + 2))
		{
			ft_putendl("exit : too much argument.");
			return (-1);
		}
	}
	exit((char)ret);
}
