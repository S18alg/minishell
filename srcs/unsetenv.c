
#include "minishell.h"

static char	**st_getlast(char **env)
{
	if (!*env)
		return (env);
	while (*(env + 1))
		env++;
	return (env);
}

int		bi_unsetenv(char **env, char *var)
{
	char	**last;
	int		len;

	if (!*env)
		return (0);
	len = ft_strlen(var);
	last = st_getlast(env);
	while (!ft_strncmp(*env, var, len))
		env++;
	free(*env);
	*env = *last;
	*last = NULL;
	return (1);
}
