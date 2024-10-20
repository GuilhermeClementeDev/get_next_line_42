#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int	fd;

	fd = open("test.txt",O_RDONLY);
	if (fd == -1)
		return (printf("-1\n"));
	printf ("%d", fd);
}
