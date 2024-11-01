#include "get_next_line.h"

char	*ft_newstr(char *s)
{
	int		size;
	char	*new;

	size = 0;
	while (s[size] != '\n')
		size++;
	new =(char *)malloc(size + 2);
	if (!new)
		return (ft_free(s));
	new[size + 1] = '\0';
	new = (char *)ft_memcpy(new, s, size);
	s = ft_free(s);
	return(new);
}
static char	*extract_l(char *s)
{
	char	*new;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while(s[size] && s[size] != '\n')
		size++;
	if (!s[size])
		return (NULL);
	new = (char *)malloc((ft_strlen(s) - (size + 1)) + 1);
	if (!new)
		return (NULL);
	size++;
	while(s[size + i])
	{
		new[i] = s[size + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static int ft_verify(char *str)
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
	static char	*cont;
	char	*string;
	char	*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	string = read_f(fd, tmp, cont);
	tmp = ft_free(tmp);
	if (!string)
		return (NULL);
	cont = extract_l(string);
	if (cont && cont[0] != '\0')
		string = ft_newstr(string);
	if (cont && cont[0] == '\0')
		cont = ft_free(cont);
	return (string);
}
