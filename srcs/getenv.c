/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:08:43 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/10 17:18:57 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *	@name :		getenv
 *	@brief :	return a pointer on a ENV variable
 */
char	*getenv(char **env, char *name)
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
