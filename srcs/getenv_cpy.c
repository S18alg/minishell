/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv_cpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 17:08:43 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/24 16:09:09 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getenv_cpy(char **env, char const *name)
{
	char	*new;
	size_t	len;

	len = ft_strlen(name);
	while (*env)
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
