
#include "minishell.h"

/*!
 *	@name : bi_history_print
 *	@brief : print the content of history, return the number of commande.
 */
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
