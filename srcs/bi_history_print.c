/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_history_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-guil <sle-guil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 14:17:56 by sle-guil          #+#    #+#             */
/*   Updated: 2015/03/24 16:08:39 by sle-guil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		bi_history_print(t_list *lst)
{
	int		i;

	ft_putendl("Command history :");
	i = 0;
	while (lst)
	{
		ft_putendl(*((char**)lst->content));
		lst = lst->next;
		i++;
	}
	ft_putnbr(i);
	ft_putendl(" command stored in history.");
	return (i);
}
