/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:42:14 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/20 07:51:46 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
ft_strchr devuelve un puntero al primer carácter que este en set
Si esta en el set, se descarta el caracter en la función trim.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1 || !set)
		return (0);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != 0)
		i++;
	j = ft_strlen(s1);
	while (j > i && ft_strchr(set, s1[j]) != 0)
		j--;
	trim = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!trim)
		return (0);
	while (i <= j)
		trim[k++] = s1[i++];
	trim[k] = '\0';
	return (trim);
}
