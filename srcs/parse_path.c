
#include "minishell.h"

/*
 * @name :		parse_path
 * @brief :		parse the PATH variable into a char** for each path.
 */

static char	*st_free(char **t, int i)
{
	char	*ret;

	ret = t[i];
	i = 0;
	while (t[i])
		free(t[i++]);
	free(t);
	return (ret);
}

char	*parse_path(char *path, char *cmd)
{
	char	*new;
	char	*tmp;
	char	**dir;
	int		i;

	i = 0;
	dir = ft_strsplit(path, ':');
	tmp = ft_strcdup(cmd, ' ');
	while (dir[i])
	{
		new = ft_strjoin(dir[i], tmp);
		if (st_test(new))
			break ;
		free(new);
		i++;
	}
	free(tmp);
	tmp = st_free(dir, i);
	if (tmp)
		return (new);
	free(new);
	return (NULL);
}
