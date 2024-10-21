#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

#ifndef BUFFER_H
#define BUFFER_H

#define BUFFER_SIZE 42

#endif

typedef struct s_list
{
	char			*string;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);

#endif
