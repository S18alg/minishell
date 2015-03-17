/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 17:27:50 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/17 15:53:37 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		bi_setenv(char **env, char *var, int owrite)
{
	char	*new;
	char	**tmp

	tmp = ft_strsplit(var); 
	if (!tmp[0] || !tmp[1] || tmp[2])
		return (st_error_arg());
	while (env[i])
		i++;
}
