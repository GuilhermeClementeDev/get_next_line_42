#include "get_next_line.h"

char	*ft_free(char *tmp)
{
	free(tmp);
	tmp = NULL;
	return (tmp);
}

static int	ft_verify(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if(s[i] == '\n')
			return (1);
		i++;
	}
	if (i != BUFFER_SIZE)
		return (1);
	return (0);
}

char	*read_f(int fd, char *tmp, char *cont)
{
	int	i;
	int veri;
	char *str;

	i = 1;
	veri = 0;
	str = NULL;
	while (i != 0)
	{
			i = read(fd, tmp, BUFFER_SIZE);
			if (i == -1)
				return (NULL);
			veri = ft_verify(tmp);
			if (veri == 1)
			{
				str = ft_djoin(str, tmp, cont);
				i = 0;
			}
			else
				str = ft_join(str, tmp);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*cont;
	char 		*tmp;
	char		*string;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	string = read_f(fd, tmp, cont);
	tmp = ft_free(tmp);
	if (string == NULL)
		return (NULL);
	return (string);
}
