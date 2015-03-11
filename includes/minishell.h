/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 15:32:43 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/11 17:18:44 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <dirent.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

# include <sys/stat.h>
# include <sys/wait.h>
# include <signal.h>

# include "libft.h"

/*!
 *	@name : User interface
 *	@brief : Print information to users
 */
void	print_prompt(void);
char	**env_cp(char **env);

char	*getenv_p(char **env, char *name);
char	*getenv_cpy(char **env, char *name);

/*!
 *	@name : Command parsing
 *	@brief : Parse a command so ft_strsplit(cmd, ' ') can be used in execve
 */
int		interpreter(char **env);
char	**parse(char *cmd);
char	*parse_path(char const *path, char const *cmd);

int		testpath(char *path);
/*!
 *	@name :		Execution
 *	@brief :	managment of the execution environment
 *				and error management
 */
int		builtins(char const *cmd, char **env);
void	runcmd(char const *cmd, char **env);

void	er_notfound(char const *cmd);

/*!
 *	@name : 	Builtins function
 *	@brief :	This function are intergrated to the minishell
 */
int		bi_env(char **env);

/*!
 *	History management
 *		Macro :
 *	- definition of the possible use of the function
 *		Use are describe in the history.c files
 *		Function :
 *	- History : general management
 */
# define H_RESET	1
# define H_SAVE		2
# define H_UP		4
# define H_DOWN		8
# define H_SEARCH	16

char	*history(char const *line, int action);

#endif
