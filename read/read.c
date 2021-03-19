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
	ssize_t ret = 0;
	char buf[32] = {0};

    fd = open("test.c",O_CREAT|O_RDWR,0666);

    if(fd < 0)
    {
        printf("file open is error\n");
		return -1;
    }
    printf("fd is %d\n",fd);

	ret = read(fd,buf,32);
	if(ret < 0)
	{
		printf("file read is error.\n");
	}
	printf("the ret is %ld\n",ret);
	printf("the buf is %s",buf);	

	ret = read(fd,buf,32);
	printf("ret is %ld\n",ret);
	
	close(fd);

    return 0;
}
