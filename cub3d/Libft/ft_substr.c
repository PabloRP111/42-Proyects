/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:41:47 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/18 12:31:51 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (0);
	while (s[i] != '\0' && i < start)
		i++;
	while (s[i] != '\0' && j < len)
		substr[j++] = s[i++];
	substr[j] = '\0';
	return (substr);
}
/*
int main(void)
{
    char *str = "Hola mundo";
    char *str2 = ft_substr(str, 2, 4);
    printf("%s\n", str2);
    return (0);
}*/
