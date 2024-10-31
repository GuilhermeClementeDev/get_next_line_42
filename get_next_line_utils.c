#include "get_next_line.h"

char	*ft_free(char *tmp)
{
	free(tmp);
	tmp = NULL;
	return (tmp);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int				size;
	char			*ptr;

	size = ft_strlen(s);
	ptr = (char *)malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	ptr[size] = '\0';
	size--;
	while (size >= 0)
	{
		ptr[size] = s[size];
		size--;
	}
	return (ptr);
}

void	ft_cat(char *dst, char *src)
{
	int	i;
	int d;

	i = ft_strlen(dst);
	d = 0;
	while(src[d])
	{
		dst[i + d] = src[d];
		d++;
	}
	dst[i + d] = '\0';
}

char	*ft_join(char *s1, char *s2)
{
	unsigned int	size;
	char			*arr;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	arr = (char *)malloc(size);
	if (arr != NULL)
	{
		arr[0] = '\0';
		ft_cat(arr, s1);
		s1 = ft_free(s1);
		ft_cat(arr, s2);
		return (arr);
	}
	return (NULL);
}
