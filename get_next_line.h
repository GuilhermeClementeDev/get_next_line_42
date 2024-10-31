#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

char	*get_next_line(int fd);

char	*ft_join(char *s1, char *s2);

char	*ft_free(char *tmp);

char	*ft_strdup(char *s);

#endif
