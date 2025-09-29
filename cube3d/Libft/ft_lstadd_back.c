/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:45:49 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/19 19:03:24 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

/*
int main(void)
{
	t_list	*lst = ft_lstnew("Hello");
	ft_lstadd_front(&lst, ft_lstnew("Hola"));
	ft_lstadd_back(&lst, ft_lstnew("Bonjour"));
	printf("%s\n", lst->content);
	printf("%s\n", ft_lstlast(lst)->content);
	printf("%s\n", lst->next->content);
	return (0);
}*/