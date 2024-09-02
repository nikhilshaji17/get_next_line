#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd = open("notes3.txt", O_RDONLY);
	// int fd = 50;
	int flag = 1;
	while (flag)
	{
		char *sentence = get_next_line(fd);
		if (sentence == NULL)
		{
			flag = 0;
			break ;
		}
		printf("%s", sentence);
		free(sentence);
	}
}