/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 15:41:14 by gozsertt          #+#    #+#             */
/*   Updated: 2020/01/08 12:09:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl		*fdselect(t_gnl **rootp, int fd)
{
	t_gnl				*head;

	if (*rootp == NULL)
	{
		if (!(*rootp = malloc(sizeof(t_gnl)))
			|| !((*rootp)->vct = gnl_vct_new(VCT_DEFSIZE)))
			return (NULL);
		(*rootp)->next = NULL;
		return (*rootp);
	}
	head = *rootp;
	while (head)
	{
		if (head->fd == fd)
			return (head);
		if (head->next == NULL)
			break ;
		head = head->next;
	}
	if (!(head->next = malloc(sizeof(t_gnl)))
		|| !(head->next->vct = gnl_vct_new(VCT_DEFSIZE)))
		return (NULL);
	head->next->next = NULL;
	return (head->next);
}

void				gnl_freenode(t_gnl **rootp, int fd, t_gnl *head)
{
	t_gnl				*prev;

	head = *rootp;
	if ((*rootp)->fd == fd)
	{
		*rootp = (*rootp)->next;
		free(head->vct->str);
		free(head->vct);
		free(head);
		return ;
	}
	while (head)
	{
		if (head->fd == fd)
		{
			prev->next = head->next;
			free(head->vct->str);
			free(head->vct);
			free(head);
			break ;
		}
		prev = head;
		head = head->next;
	}
}

static char			*gnl_strndup(const char *src, int len)
{
	int		i;
	char	*ret;

	if (len <= 0)
		return (NULL);
	if (!(ret = malloc(sizeof(char) * len + 1)))
		return (NULL);
	ret[len] = '\0';
	i = 0;
	while (i < len)
	{
		ret[i] = src[i];
		i++;
	}
	return (ret);
}

int					get_next_line(int fd, char **line)
{
	static	t_gnl	*root;
	t_gnl			*head;
	char			buf[BUFFER_SIZE];
	int				ret;
	int				i;

	if (!line || fd < 0 || !(head = fdselect(&root, fd)) || read(fd, 0, 0) < 0)
		return (-1);
	head->fd = fd;
	while (gnl_strnchr_idx(head->vct->str, '\n', head->vct->len, 1) == -1)
	{
		if ((ret = read(fd, buf, BUFFER_SIZE)) <= 0)
			break ;
		gnl_vct_appnstr(head->vct, &(*buf), ret);
	}
	if (ret != -1 && (ret = read(fd, buf, BUFFER_SIZE)) != -2)
		gnl_vct_appnstr(head->vct, buf, ret);
	i = gnl_strnchr_idx(head->vct->str, '\n', head->vct->len, 2);
	*line = (i == 0 ? gnl_strndup("", 1) : gnl_strndup(head->vct->str, i));
	if (ret != -1)
		ret = (head->vct->str[i] == '\n') ? 1 : 0;
	gnl_vct_cutnfrom(head->vct, 0, i + 1);
	if (head->vct->len == 0)
		gnl_freenode(&root, head->fd, head);
	return (ret);
}
