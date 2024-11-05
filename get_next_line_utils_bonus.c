#include "get_next_line_bonus.h"

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
	ptr = (char *)malloc(sizeof(char) * (size + 1));
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

void	*ft_memcpy(void *dest, const void *src, int n)
{
	int				i;
	unsigned char	*dst;
	unsigned char	*fake_src;

	i = 0;
	dst = (unsigned char *)dest;
	fake_src = (unsigned char *)src;
	while (i < n)
	{
		dst[i] = fake_src[i];
		i++;
	}
	return (dest);
}

char	*ft_join(char *s1, char *s2)
{
	unsigned int	size1;
	unsigned int	size2;
	char			*arr;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (arr != NULL)
	{
		arr = (char *)ft_memcpy(arr, s1, size1);
		ft_memcpy(arr + size1, s2, size2);
		arr[size1 + size2] = '\0';
		return (arr);
	}
	return (NULL);
}
