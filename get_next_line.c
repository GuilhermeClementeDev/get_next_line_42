#include "get_next_line.h"

static char	*extract_l(char *cont)
{
	char	*new;
	int		size;
	char	*tmp;

	size = 0;
	while(cont[size] && cont[size] != '\n')
		size++;
	if (cont[size])
	{
		size++;
		tmp = ft_strdup(&cont[size]);
	}
	else
		tmp = ft_strdup("");
	new = (char *)malloc(size + 1);
	if (!new)
		return (NULL);
	new[size] = '\0';
	size--;
	while (size >= 0)
	{
		new[size] = cont[size];
		size--;
	}
	cont = ft_free(cont);
	cont = tmp;
	printf("%s", cont);
	return (new);
}

static int ft_verify(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnull(int rz, char *tmp)
{
	while(tmp[rz])
	{
		tmp[rz] = '\0';
		rz++;
	}
}

static char	*read_f(int fd, char *cont)
{
	int		rz;
	char	*tmp;

	rz = 1;
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	while (rz != 0)
	{
		rz = read(fd, tmp, BUFFER_SIZE);
		printf("%d %s\n", rz, tmp);
		if (rz == -1)
			return (NULL);
		if (rz == 0)
			break ;
		if (rz < BUFFER_SIZE)
			ft_putnull(rz, tmp);
		if (!cont)
			cont = ft_strdup("");
		cont = ft_join(cont, tmp);
		if (ft_verify(tmp))
			break ;
	}
	tmp = ft_free(tmp);
	return (cont);
}

char	*get_next_line(int fd)
{
	static char	*cont = NULL;
	char	*string;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	cont = read_f(fd, cont);
	string = extract_l(cont);
	return (string);
}
