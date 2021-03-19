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
	char buf[32] = {"helloworld!"};

	fd = open("test.c",O_CREAT|O_RDWR,0666);
	if(fd < 0)
	{
		printf("open is error\n");
	}
	
	ret = write(fd,buf,11);	
	if(ret < 0)
	{
		printf("write is error\n");
	}	
	printf("ret is %ld\n",ret);
	
	close(fd);
    return 0;
}
