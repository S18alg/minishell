/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:19:38 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/10 17:28:26 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_cd(char **env, char *cmd)
{
	char	*new_pwd;
	char	*tmp;
	char	*home;
	char	*pwd;

	cmd = ft_strchr(cmd, ' ');
	if (cmd)
		cmd++;
	home = getenv(env, "HOME");
	pwd = get_cpyenv(env, "PWD");
	tmp = ft_strchr(home, '=') + 1;
}
