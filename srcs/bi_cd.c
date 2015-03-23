/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 14:19:38 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/23 20:13:12 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*st_init(char **env, char *s)
{
	char	*ret;
	char	*tmp;

	if (s)
		s++;
	else
		return (getenv_cpy(env, "HOME"));
	if (*s == '~')
	{
		tmp = getenv_cpy(env, "HOME");
		ret = ft_strjoin(tmp, s + 1);
		free(tmp);
	}
	else if (*s == '-' && !*(s + 1))
		ft_putendl((ret = getenv_cpy(env, "OLDPWD")));
	else
		ret = ft_strdup(s);
	return (ret);
}

static void	st_setold(char **env)
{
	char	*pwd;

	pwd = getenv_cpy(env, "PWD");
	while (*env && ft_strncmp(*env, "OLDPWD", 6))
		env++;
	if (pwd)
	{
		if (*env)
			free(*env);
		*env = ft_strjoin("OLDPWD=", pwd);
	}
	if (pwd)
		free(pwd);
}

static void	st_setpwd(char **env)
{
	char	*pwd;
	char	*buff;

	buff = malloc(sizeof(char) * 1025);
	pwd = getcwd(buff, 1024);
	while (*env && ft_strncmp(*env, "PWD", 3))
		env++;
	if (*env)
		free(*env);
	*env = ft_strjoin("PWD=", pwd);
	free(buff);
}

void		bi_cd(char **env, char *cmd)
{
	cmd = st_init(env, cmd);
	if (chdir(cmd) == -1)
	{
		ft_putstr("cd: Directory not found : ");
		ft_putendl(cmd);
		return ;
	}
	else
	{
		st_setold(env);
		st_setpwd(env);
	}
	free(cmd);
}
