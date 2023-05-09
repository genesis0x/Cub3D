/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hahadiou <hahadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:11:47 by hahadiou          #+#    #+#             */
/*   Updated: 2023/05/09 18:00:14 by hahadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_words(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	word_len(char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	**ft_split(char *s, char c, int i, int j)
{
	int		k;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			k = 0;
			res[j] = (char *)malloc(sizeof(char) * (word_len(s, c, i) + 1));
			if (!res[j])
				return (NULL);
			while (s[i] != c && s[i])
				res[j][k++] = s[i++];
			res[j][k] = '\0';
			j++;
		}
	}
	res[j] = 0;
	return (res);
}
