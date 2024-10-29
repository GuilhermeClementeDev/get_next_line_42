#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int	fd;
	char *a;

	fd = open("test.txt",O_RDONLY);
	if (fd == -1)
		return (printf("-1\n"));
	a = get_next_line(fd);
	while(a)
	{
		printf("%s",a);
		free(a);
		a = get_next_line(fd);
	}


}
