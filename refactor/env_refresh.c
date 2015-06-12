/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_refresh.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 14:15:18 by sle-guil          #+#    #+#             */
/*   Updated: 2015/04/14 16:46:18 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_refresh(char **env)
{
	char	**new;

	new = env_cp(env);
	ft_freesplit(env);
	return (new);
}
