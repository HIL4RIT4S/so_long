/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeliani <imeliani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:48:47 by imeliani          #+#    #+#             */
/*   Updated: 2022/11/27 13:22:04 by imeliani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	word_count(const char *s, char c)
{
	size_t	i;
	size_t	j;

	j = 1;
	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	return (j);
}

static void	clear(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	index;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * (word_count(s, c)));
	if (!str || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		index = i;
		while (s[i] != c && s[i])
			i++;
		str[j] = ft_substr(s, index, i - index);
		if (!str[j++])
			clear(str);
	}
	str[j] = 0;
	return (str);
}
