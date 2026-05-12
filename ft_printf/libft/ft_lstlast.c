/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:18:50 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/19 20:09:59 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
		lst = lst->next;
	return (lst);
}

/*
int main(void)
{
	t_list	*lst = ft_lstnew("Hello");
	ft_lstadd_front(&lst, ft_lstnew("Hola"));
	ft_lstadd_front(&lst, ft_lstnew("Bonjour"));
	printf("%s\n", lst->content);
	printf("%s\n", ft_lstlast(lst)->content);
	printf("%s\n", lst->next->content);
	return (0);
}
*/