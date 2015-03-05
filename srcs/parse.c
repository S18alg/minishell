/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:45:50 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/05 17:43:06 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

char	**parse(char *cmd)
{
	char	**new;

	// delete useless space here
	new = ft_strsplit(cmd, ';');
	return (new);
}
