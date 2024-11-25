/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guclemen <guclemen@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 07:50:24 by guclemen          #+#    #+#             */
/*   Updated: 2024/11/13 07:50:26 by guclemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_newstr(char *s)
{
	char	*str;
	int		size;

	size = 0;
	while (s[size] && s[size] != '\n')
		size++;
	str = (char *)malloc(sizeof(char) * (size + 2));
	if (!str)
		return (NULL);
	str = ft_memcpy(str, s, size + 1);
	str[size + 1] = '\0';
	s = ft_free(s);
	return (str);
}

static char	*extract_l(char *s)
{
	int		size;
	char	*str;
	int		full_size;

	size = 0;
	while (s[size] && s[size] != '\n')
		size++;
	if (s[size] == '\0')
		return (NULL);
	full_size = (ft_strlen(s) - (size));
	str = (char *)malloc(sizeof(char) * full_size);
	if (!str)
		return (NULL);
	str = ft_memcpy(str, &s[size + 1], full_size);
	return (str);
}

static int	ft_verify(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*read_f(int fd, char *tmp, char *cont)
{
	int		rz;
	char	*old_cont;

	rz = 1;
	old_cont = NULL;
	while (rz != 0)
	{
		rz = read(fd, tmp, BUFFER_SIZE);
		if (rz == -1)
			return (NULL);
		if (rz == 0)
			break ;
		tmp[rz] = '\0';
		if (!cont)
			cont = ft_strdup("");
		old_cont = cont;
		cont = ft_join(old_cont, tmp);
		old_cont = ft_free(old_cont);
		if (ft_verify(tmp))
			break ;
	}
	return (cont);
}

char	*get_next_line(int fd)
{
	static char	*cont[1024];
	char		*string;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	string = read_f(fd, tmp, cont[fd]);
	tmp = ft_free(tmp);
	if (!string)
		return (NULL);
	cont[fd] = extract_l(string);
	if (cont[fd] && *cont[fd] != '\0')
		string = ft_newstr(string);
	if (cont[fd] && *cont[fd] == '\0')
		cont[fd] = ft_free(cont[fd]);
	return (string);
}
