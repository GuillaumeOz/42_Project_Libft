/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:12:56 by gozsertt          #+#    #+#             */
/*   Updated: 2019/11/08 19:53:01 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	while (ft_is_white_space(s[len - 1]))
		len--;
	i = -1;
	while (ft_is_white_space(s[++i]))
		len--;
	if (len <= 0)
		len = 0;
	if (!(str = (char*)malloc(sizeof(char) * (len + SENTINAL))))
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < len)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
char *ft_strtrim(char const *s1, char const *set);

Paramètres #1. La chaine de caractères à trimmer.
#2. Le set de reference de caractères à trimmer.
Valeur de retour La chaine de caractères trimmée. NULL si
l’allocation échoue.
Fonctions externes autorisées
malloc
Description Alloue (avec malloc(3)) et retourne une copie de la
chaine de caractères donnée en argument, sans les
caractères spécifiés dans le set donné en argument
au début et à la fin de la chaine de caractères.

char *ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = 0;
	len = ft_strlen(s1);
	while (set[i])
	{
		while (s1[j])
		{
			if(set[i] == )
				count++
		}
	}
}