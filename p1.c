#include<stdio.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    char wrd[256]="mold"; 
    char buffer[256];
	int n, m, i, j, line;
    m = strlen(wrd);
    line = 0;

    //openng fifo
    int fd;
    fd = open("demofifo",O_WRONLY);
    
    FILE *fp;
    char c;
    //oepning dictionary
    fp = fopen("dictionary.txt","r");
    while (fgets(buffer, 256, fp) != NULL) {

		i = 0;
		n = strlen(buffer);
		while (i < n) {

			j = 0;
			while (i < n && j < m && buffer[i] == wrd[j]) {
				++i, ++j;
			}
			if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m) {
				printf("Line: %d ", line);
				printf("Column: %d\n", i - m);
			}

			while (i < n && buffer[i] != ' ') {
				++i;
			}
			++i;

		}
        //writing in fifo
        write(fd,buffer,sizeof(buffer));
        close(fd);

		++line;

	}
    fclose(fp);


    return 0;
}