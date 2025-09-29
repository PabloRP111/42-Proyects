/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:11:10 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/19 20:06:37 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 0;
	while (lst != 0)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/*
int	main(void)
{
	t_list	*lst = ft_lstnew("Hello");
	ft_lstadd_front(&lst, ft_lstnew("Hola"));
	ft_lstadd_front(&lst, ft_lstnew("Bonjour"));
	printf("%d\n", ft_lstsize(lst));
	return (0);
}
*/