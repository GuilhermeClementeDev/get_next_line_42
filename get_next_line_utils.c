#include "get_next_line.h"


static void	ft_strcat(char *dst, const char *src)
{
	int	i;
	int	d;

	d = 0;
	i = 0;
	while(dst[d])
		d++;
	while (src[i])
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
}

char	*ft_join(char const *s1, char const *s2)
{
	int	size;
	char	*arr;
	int	i;

	i = 0;
	size = 0;
	while (s1[i])
		i++;
	while (s2[size])
		size++;
	arr = (char *)malloc((size + i) + 1);
	if (arr != NULL)
	{
		ft_strcat(arr, s1);
		ft_strcat(arr, s2);
		return (arr);
	}
	return (NULL);
}
char	*ft_djoin(char const *s1, char const *s2, char *extra)
{
	int		i;
	char	*new;
	int		d;

	d = 0;
	i = 0;
	new = (char *)malloc(BUFFER_SIZE + 1);
	if (new == NULL)
		return (NULL);
	extra = (char *)malloc(BUFFER_SIZE + 1);
	if (extra == NULL)
		return (NULL);
	extra[BUFFER_SIZE] = '\0';
	while (s2[i] != '\n' && s2[i] != '\0')
	{
		new[i] = s2[i];
		i++;
	}
	new[i] = '\0';
	i++;
	while (s2[i + d])
	{
		extra[d++] = s2[i + d];
	}
	return(ft_join(s1, new));
}
