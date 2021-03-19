#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage:%s <Srcfile> <Objfile>\n",argv[0]);
		return -1;
	}	
	
	int fd_src,fd_obj;
	char buf[20]={0};
	ssize_t ret;

	fd_src = open(argv[1],O_RDWR,0666);
	if(fd_src < 0)
	{
		printf("open is error\n");
		return -1;
	}
	fd_obj = open(argv[2],O_CREAT|O_RDWR,0666);
	if(fd_src < 0)
	{
		printf("open is error\n");
		return -1;
	}
	while((ret=read(fd_src,buf,20)) != 0)
	{
		write(fd_obj,buf,ret);
	};
	
	close(fd_src);
	close(fd_obj);

	return 0;
}
