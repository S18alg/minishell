/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 13:58:45 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/10 14:11:18 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 *	@name :		bi_env
 *	@brief :	Print the environment variables
 */
int		bi_env(char *env)
{
	while (*env)
	{
		ft_putendl(*env++);
	}
	return (0);
}
