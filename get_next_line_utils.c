#include "get_next_line.h"
#include <stdio.h>

char	*ft_free(char *tmp)
{
	free(tmp);
	tmp = NULL;
	return (tmp);
}
static void	ft_strcat(char *dst, char *src)
{
	int	i;
	int	d;

	d = 0;
	i = 0;
	if (!dst || !src)
		return;
	while(dst[d])
		d++;
	while (src[i])
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
}

char	*ft_join(char *s1, char *s2)
{
	int	size;
	char	*arr;
	int	i;

	if (!s2 || !s1)
		return (NULL);
	i = 0;
	size = 0;
	if(s1)
	{
		while (s1[i])
			i++;
	}
	while (s2[size])
		size++;
	arr = (char *)malloc((size + i) + 1);
	if (arr != NULL)
	{
		if (s1)
		{
			ft_strcat(arr, s1);
				ft_free(s1);
		}
		ft_strcat(arr, s2);
		return (arr);
	}
	return (NULL);
}
