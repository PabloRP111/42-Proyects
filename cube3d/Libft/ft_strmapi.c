/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:50:04 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/15 07:10:41 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
char	*ft_aux(unsigned int n, char c) {
	printf("%d ", n);
    printf("%c\n", c);
    char *result = malloc(sizeof(char));
    result[0] = c;
    return result;
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	result = (char *)malloc(ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	while (s[i] != '\0')
	{
		result[i] = (*f)(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
int	main(void)
{
	char    *str = "Hola";
    char    *(*f)(unsigned int, char);
    char    *result;

    f = &ft_aux;
    result = ft_strmapi(str, (char (*)(unsigned int, char))f);
    printf("%s\n", result);
    free(result);
    return 0;
}
*/