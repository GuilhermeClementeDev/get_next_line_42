#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);

char	*ft_join(char *s1, char *s2);

char	*ft_djoin(char *s1, char *s2, char *extra);

char	*ft_free(char *tmp);
#endif
