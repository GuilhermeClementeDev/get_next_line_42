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
	char * test =get_next_line (fd);
	int i = 0;
	while (test[i])
	{
		printf(" %d-%c", i, test[i]);
		i++;
	}
	//printf("!-%s",test);
	test =get_next_line (fd);
	//printf("!-%s",test);
	test =get_next_line (fd);
	//printf("!-%s",test);
	free(test);

	return 0;

}
