#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv)
{
	int fd = 0;
	char buf[20] = {0};
	ssize_t ret_read = 0;
	ssize_t ret_write = 0;

	fd = open("a.c",O_CREAT|O_RDWR,0666);
	if(fd < 0)
	{
		printf("file open is error!\n");
		return -1;
	}
	
	ret_read = read(fd,buf,20);
	if(ret_read < 0)
	{
		printf("file read is error!\n");
	}
	printf("ret_read is %ld\n",ret_read);
	printf("read is %s",buf);
	close(fd);
	
	fd = open("b.c",O_CREAT|O_RDWR,0666);
	if(fd < 0)
	{
		printf("file open is error!\n");
		return -1;
	}
	ret_write = write(fd,buf,ret_read);
	if(ret_write < 0)		
	{
		printf("file write is error!\n");
	}
	printf("ret_write is %ld\n",ret_write);
	close(fd);

	return 0;
}
