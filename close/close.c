#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   //
   //
	int fd = 0;
	int fd_close = 0;
    fd = open("open.c",O_CREAT|O_RDWR,0666);

    if(fd < 0)
    {
        printf("file open is error\n");
    }

    printf("fd is %d\n",fd);
	fd_close = close(fd);
	if(fd_close < 0)
	{
		printf("file close is error.\n");
	}
	printf("fd_close is %d\n",fd_close);
 
    return 0;
}

