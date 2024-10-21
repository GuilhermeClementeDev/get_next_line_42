#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char 			arr[BUFFER_SIZE];
	long long int	c;
	unsigned int	i;
	t_list			*tmp;
	t_list			*start;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	c = read(fd, arr, BUFFER_SIZE);
		if (c == -1)
			return (NULL);
	tmp = NULL;
	while ()
	{
		while()
		{
			ptr = t_lstnew(ft_strdup(arr));
			ft_lstadd_back(&start, tmp);
		}
	}
	return (ptr);
}
