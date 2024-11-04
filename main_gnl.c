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
	//get_next_line (fd);
	char * test = NULL;
	test = get_next_line (fd);
	/*while (test)
	{
		printf(":%s:\n", test);
		free(test);
		test = get_next_line(fd);
	}*/
	printf("!-%s",test);
	//free(test);
	//test = get_next_line (fd);
	//printf("!-%s",test);
	//free(test);
	//test = get_next_line (fd);
	//printf("!-%s",test);
	if (test)
		free(test);
	return 0;

}
