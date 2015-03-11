/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:08:43 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/11 15:34:56 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 *	@name :		get_cpyenv
 *	@brief :	get and return a new allocated string contening the value
 *				of a ENV variable.
 */
char	*getenv_cpy(char **env, char *name)
{
	char	*new;
	size_t	len;

	len = ft_strlen(name);
	while (env && *env)
	{
		if (!ft_strncmp(*env, name, len))
		{
			new = ft_strdup(ft_strchr(*env, '=') + 1);
			return (new);
		}
		env++;
	}
	return (NULL);
}
