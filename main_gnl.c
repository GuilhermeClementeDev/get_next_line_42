#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int	fd;
	fd = open("test.txt",O_RDONLY);
	if (fd == -1)
		return (printf("-1\n"));
	printf("\n%s",get_next_line (fd));
}
