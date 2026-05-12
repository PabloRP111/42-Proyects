/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:26:11 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/19 20:10:44 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = tmp;
	}
	*lst = NULL;
}

/*
void del(void *content) {
    free(content);
}

int main(void)
{
    t_list *lst = ft_lstnew(ft_strdup("Node 1"));
    lst->next = ft_lstnew(ft_strdup("Node 2"));
    ft_lstadd_front(&lst, ft_lstnew(strdup("Node 0")));

    printf("Contenido antes de llamar a ft_lstclear:\n");
    t_list *current = lst;
    while (current)
	{
        printf("%s\n", (char *)current->content);
        current = current->next;
    }

    ft_lstclear(&lst, del);

    printf("Contenido después de llamar a ft_lstclear:\n");
    current = lst;
    while (current) {
        printf("%s\n", (char *)current->content);
        current = current->next;
    }
    return 0;
}
*/
