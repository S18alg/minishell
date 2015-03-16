/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 17:27:50 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/16 18:24:37 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_setenv(char **env, char *var, int owrite)
{
	char	*newvar;

	while (env[i])
		i++;
	new = st_dup(var);
	env[i] = new;
}
