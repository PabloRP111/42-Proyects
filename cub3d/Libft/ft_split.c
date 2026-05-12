/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prosas-p <prosas-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:09:23 by prosas-p          #+#    #+#             */
/*   Updated: 2023/12/13 18:06:22 by prosas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*extract_word(const char *s, char c, int *i)
{
	int		k;
	char	*word;

	k = 0;
	while (s[*i + k] != '\0' && s[*i + k] != c)
		k++;
	word = (char *)malloc(sizeof(char) * (k + 1));
	if (word == NULL)
		return (NULL);
	k = 0;
	while (s[*i] != '\0' && s[*i] != c)
	{
		word[k] = s[*i];
		(*i)++;
		k++;
	}
	word[k] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			str[j] = extract_word(s, c, &i);
			if (str[j] == NULL)
				return (NULL);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

/*
int main()
{
    char *str = "Uno, dos, tres, cuatro, cinco, seis, siete, ocho, nueve, diez";
    char c = ',';
    char **str2;
    int i;

    str2 = ft_split(str, c);
    if (str2 == NULL)
    {
        fprintf(stderr, "Error al dividir la cadena\n");
        return (1);
    }

    i = 0;
    while (str2[i] != NULL)
    {
        printf("%s\n", str2[i]);
        free(str2[i]);
        i++;
    }
    free(str2);
    return (0);
}
*/