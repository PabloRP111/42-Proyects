/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:55:36 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/18 07:58:15 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*pts1;
	char	*pts2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	pts1 = (char *) s1;
	pts2 = (char *) s2;
	str = (char *) malloc((ft_strlen(pts1) + ft_strlen(pts2) + 1));
	if (!str)
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
/*
int main(void)
{
    char *str = "Hola ";
    char *str2 = "mundo";
    char *str3 = ft_strjoin(str, str2);
    printf("%s\n", str3);
    return (0);
}*/
