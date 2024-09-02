#include <stdio.h>
#include "get_next_line_bonus.h"

// int main()
// {
// 	int fd = open("notes.txt", O_RDONLY);
// 	int fd2 = open("notes2.txt", O_RDONLY);
// 	int fd3 = open("notes3.txt", O_RDONLY);
// 	int fd4 = open("notes4.txt", O_RDONLY);	
// 	char *sentence = get_next_line(fd);
// 	while (sentence != NULL)
// 	{
// 		printf("%s", sentence);
// 		sentence = get_next_line(fd);
// 	}
// 	char *sentence_two = get_next_line(fd2);
// 	while (sentence_two != NULL)
// 	{
// 		printf("%s", sentence_two);
// 		sentence_two = get_next_line(fd2);
// 	}
// 	char *sentence_three = get_next_line(fd3);
// 	while (sentence_three != NULL)
// 	{
// 		printf("%s", sentence_three);
// 		sentence_three = get_next_line(fd3);
// 	}
// 	char *sentence_four = get_next_line(fd4);
// 	while (sentence_four != NULL)
// 	{
// 		printf("%s", sentence_four);
// 		sentence_four = get_next_line(fd4);
// 	}
// }

int main()
{
	int fd = open("notes.txt", O_RDONLY);
	int fd2 = open("notes2.txt", O_RDONLY);
	int fd3 = open("notes3.txt", O_RDONLY);
	char *sentence;
	int flag = 0;
	// int fd4 = open("notes4.txt", O_RDONLY);	
	while (flag != 1)
	{
		sentence = get_next_line(fd);
		if (!sentence)
			flag = 1;
		printf("%s", sentence);
		sentence = get_next_line(fd2);
		if (!sentence)
			flag = 1;
		printf("%s", sentence);
		sentence = get_next_line(fd3);
		if (!sentence)
			flag = 1;
		printf("%s", sentence);
		// sentence = get_next_line(fd4);
		// printf("%s", sentence);
	}
}