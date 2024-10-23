#include "get_next_line.h"

int	ft_verify(char *s)
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

char	*get_next_line(int fd)
{
	static char	*extra = NULL;
	char 		*tmp;
	char		*string;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	while (i == 0)
	{
			if (read(fd, tmp, BUFFER_SIZE) == -1)
				return (NULL);
			i = ft_verify(tmp);
			if (i == 1)
				ft_djoin(tmp, extra);
			else
				string = ft_join(string, tmp);
	}
	return (string);
}
