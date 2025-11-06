/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalbano <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:46:07 by aalbano           #+#    #+#             */
/*   Updated: 2025/06/27 11:50:08 by aalbano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*malloc_word(const char *s, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_all(char **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
}

static int	fill_split(char **res, const char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] && s[len] != c)
				len++;
			res[i] = malloc_word(s, len);
			if (!res[i])
				return (free_all(res, i), 1);
			i++;
			s += len;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	res = (char **) malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	if (fill_split(res, s, c))
		return (NULL);
	return (res);
}
