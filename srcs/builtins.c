/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 14:03:01 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/09 14:22:35 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtins(char const *cmd, char **env)
{
	(void)env;
	if (!ft_strcmp(cmd, "exit"))
		exit(0);
	return (1);
}
