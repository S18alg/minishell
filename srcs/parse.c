/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 17:45:50 by sle-guil          #+#    #+#             */
/*   Updated: 2015/02/25 14:22:46 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

char	*parse(char *cmd)
{
	//char	**new;
	char	*s;

	//new = malloc(sizeof(char*));
	s = ft_strdup(cmd);
	return (s);
}
