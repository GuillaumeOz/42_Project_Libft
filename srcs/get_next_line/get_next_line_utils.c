/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:40:03 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 15:21:00 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl_vector	*gnl_vct_new(size_t size)
{
	t_gnl_vector	*vct;
	size_t		i;

	size += 1;
	if (!(vct = malloc(sizeof(t_gnl_vector))))
		return (NULL);
	if (vct != NULL)
	{
		vct->size = size;
		if (!(vct->str = malloc(size)))
			return (NULL);
		vct->quart = size / 4;
		vct->len = 0;
	}
	i = 0;
	while (i < size)
	{
		vct->str[i] = '\0';
		i++;
	}
	return (vct);
}

int			gnl_vct_extend(t_gnl_vector *vct, size_t expected_len)
{
	char	*tmp;
	size_t	i;

	if (vct == NULL || vct->size == 0)
		return (SUCCESS);
	tmp = vct->str;
	while (vct->size <= expected_len)
	{
		vct->size *= 2;
		vct->quart *= 2;
	}
	if (!(vct->str = malloc(vct->size)))
		return (FAILURE);
	i = 0;
	while (i < vct->len)
	{
		vct->str[i] = tmp[i];
		i++;
	}
	free(tmp);
	tmp = NULL;
	return (SUCCESS);
}

int			gnl_vct_appnstr(t_gnl_vector *vct, char *addens, size_t n)
{
	unsigned long	i;
	size_t			expected_len;

	if (addens == NULL || vct == NULL || vct->str == NULL || n <= 0)
		return (SUCCESS);
	i = 0;
	expected_len = vct->len + n;
	if (expected_len >= vct->size)
	{
		if (gnl_vct_extend(vct, expected_len) == FAILURE)
			return (FAILURE);
	}
	while (addens[i] && i < n)
	{
		vct->str[vct->len] = addens[i];
		vct->len++;
		i++;
	}
	vct->str[vct->len] = '\0';
	return (SUCCESS);
}

int			gnl_vct_cutnfrom(t_gnl_vector *vct, size_t idx, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	newlen;

	if (vct == NULL || vct->str == NULL || idx >= vct->len)
		return (SUCCESS);
	if (idx + n > vct->len)
		n = vct->len - idx;
	i = idx;
	j = idx + n;
	newlen = idx + 1;
	while (j < vct->size)
	{
		vct->str[i] = vct->str[j];
		i++;
		j++;
	}
	vct->len -= n;
	return (SUCCESS);
}

int			gnl_strnchr_idx(char *s, char c, size_t n, int mode)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != c && i < n)
		i++;
	if (i == n)
	{
		if (c != '\0' && mode == 1)
			return (-1);
	}
	return (i);
}
