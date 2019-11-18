/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 20:56:49 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/18 13:41:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*malloc_and_get_word_list(t_list *alist, const char *s,
					int c, size_t len)
{
	char	*word;
	size_t	i;

	if (!(word = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (!(alist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	i = -1;
	while (s[++i] && s[i] != c)
		word[i] = s[i];
	word[i] = '\0';
	alist->content = word;
	return (alist);
}

t_list				**ft_strsplit_list(char const *s, char c)
{
	t_list	**alist;
	size_t	i;
	size_t	k;
	size_t	len;

	if (!s)
		return (NULL);
	if (!(alist = (t_list**)malloc(sizeof(t_list*)
			* (ft_count_elems(s, c) + 1))))
		return (NULL);
	i = -1;
	k = 0;
	while (s[++i])
	{
		if (s[i] != c)
		{
			len = ft_seglen(s, i, c);
			alist[k] = malloc_and_get_word_list(*alist, s + i, c, len);
			i += len - 1;
			k++;
		}
	}
	alist[k++] = NULL;
	return (alist);
}
