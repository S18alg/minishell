/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:08:43 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/23 14:04:02 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *	@name :		get_penv
 *	@brief :	return a pointer on a ENV variable
 */
char	*getenv_p(char **env, char *name)
{
	size_t	len;

	len = ft_strlen(name);
	while (env && *env)
	{
		if (!ft_strncmp(*env, name, len))
			return (*env);
		env++;
	}
	return (NULL);
}
