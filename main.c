#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

int main()
{
	int fd[3];

	fd[0] = open("1.txt", O_RDONLY);
	fd[1] = open("2.txt", O_RDONLY);
	fd[2] = open("3.txt", O_RDONLY);

	for(int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 3; ++j)
		{
			char *line = get_next_line(fd[j]);
			if(line != NULL)
				printf("%s", line);
			free(line);
		}
	}

	for(int i = 0; i < 3; i++)
		close(fd[i]);
	return 0;
}