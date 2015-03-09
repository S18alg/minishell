/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/05 17:43:17 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/05 18:41:21 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*!
 *	@name : History
 *	@brief : Manage the list of command enter by the user into the shell
 *	@param : A string (can be NULL) and an action defined in minishell.h
 *	@return : NULL if the function is called to save a new entry.
 *				else, it returns the ligne pointed by indice.
 *
 *	H_SAVE :		Copy the string in line into a new element.
 *	H_RESET :		Set the indice ptr to the begining of lst.
 */
char	*history(char const *line, int action)
{
	static t_list	*lst = NULL;
	static t_list	*indice = NULL;
	char			*ret;

	ret = NULL;
	if (action == H_SAVE)
		ft_lstadd(&lst, ft_lstnew(line, ft_strlen(line) + 1));
	if (action == H_RESET || action == H_SAVE)
		indice = lst;
	return (ret);
}
