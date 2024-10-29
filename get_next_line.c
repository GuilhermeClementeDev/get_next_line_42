/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:51:33 by guclemen          #+#    #+#             */
/*   Updated: 2024/10/29 09:51:37 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_verify(char *s)
{
	int	i;

	i = 0;
	//printf("\n%s", s);
	while (s && s[i])
	{
		if(s[i] == '\n')
			return (1);
		i++;
	}
	if (i < BUFFER_SIZE)
		return (1);
	return (0);
}

char	*read_f(int fd, char *cont)
{
	int	i;
	char *tmp;

	i = 1;
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (NULL);
	while (i > 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		cont = ft_join(cont, tmp);
		printf("%s", cont);
		if (!cont)
			return (NULL);
		if(ft_verify(cont))
		{
			//printf("%s", "to aqui");
			break ;
		}
	}
	ft_free (tmp);
	return (cont);
}
static char	*ft_new_cont(char *cont)
{
	int		i;
	char	*new;
	int		start;

	i = 0;
	while (cont[i] && cont[i] != '\n')
		i++;
	if (cont[i] != '\n')
		return(ft_free(cont));
	start = i + 1;
	while (cont[i])
		i++;
	new = (char *)malloc(i - start + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (cont[start])
	{
		new[i] = cont[start];
		if(new[i] == '\n')
		{
			i++;
			break;
		}
		i++;
	}
	new[i] = '\0';
	ft_free (cont);
	return (new);
}
static char	*extract_l(char *cont)
{
	int	i;
	char	*new;

	i = 0;
	if (!cont)
		return (NULL);
	while (cont[i] && cont[i] != '\n')
		i++;
	if (cont[i] == '\n')
		i++;
	new = (char *)malloc(i + 1);
	if (!new)
		return (NULL);
	new[i] = '\0';
	i--;
	while (i >= 0)
	{
		new[i] = cont[i];
		i--;
	}
	cont = ft_new_cont(cont);
	return (new);
}

char *get_next_line(int fd)
{
	static char	*cont = NULL;
	char		*string;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	cont = malloc(1);
	cont[0] = '\0';
	cont = read_f(fd, cont);
	string = extract_l(cont);
	return (string);
}
