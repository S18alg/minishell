/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:43:17 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/24 16:09:32 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		st_testempty(char const *s)
{
	while (*s)
	{
		if (!ft_isspace(*s))
			return (1);
		s++;
	}
	return (0);
}

char	*history(char *line, int action)
{
	static t_list	*lst = NULL;
	static t_list	*indice = NULL;
	char			*ret;

	ret = NULL;
	if (action == H_SAVE && st_testempty(line))
	{
		if (*line && !ft_isspace(*line))
			ft_lstadd(&lst, ft_lstnew(&line, sizeof(char *)));
		else
			free(line);
	}
	if (action == H_RESET || action == H_SAVE)
		indice = lst;
	if (action == H_PRINT)
		bi_history_print(lst);
	return (ret);
}
