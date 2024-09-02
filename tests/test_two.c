#include <stdio.h>

void log_messages(char *message)
{
	static int total = 0;
	total += 1;
	FILE *logfile = fopen("log_file.txt", "a");
	if (logfile != NULL)
	{
		fprintf(logfile, "%d : %s \n", total, message);
		fclose(logfile);
	}
}

int main()
{
	log_messages("Data read");
	log_messages("Data write");
	log_messages("Error writing data");
}