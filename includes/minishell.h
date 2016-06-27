/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/21 15:32:43 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/24 16:10:54 by sle-guil         ###   ########.fr       */
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

# include <libft.h>

void	print_prompt(char **env);
char	**env_cp(char **env);
char	**env_refresh(char **env);
void	env_free(char **env);

char	*getenv_p(char **env, char *name);
char	*getenv_cpy(char **env, char const *name);

char	**script(char const *file, char **env);
int		interpreter(char **env, int fd);
char	**parse(char *cmd);
char	*parse_path(char const *path, char const *cmd);

int		testpath(char const *path);

int		builtins(char const *cmd, char **env);
void	runcmd(char const *cmd, char **env);

void	er_notfound(char const *cmd);

void	bi_exit(char const *arg);
int		bi_env(char **env, char const *arg);
int		bi_setenv(char **env, char const *var, int overwrite);
int		bi_unsetenv(char **env, char *var);
int		bi_cd(char **env, char *var);

int		bi_history_print(t_list *lst);

# define H_RESET	1
# define H_SAVE		2
# define H_UP		4
# define H_DOWN		8
# define H_SEARCH	16
# define H_PRINT	32

char	*history(char *line, int action);

#endif
