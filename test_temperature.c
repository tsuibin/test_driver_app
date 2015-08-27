#include     <stdio.h>
#include     <stdlib.h>
#include     <unistd.h>
#include     <sys/types.h>
#include     <sys/stat.h>
#include     <fcntl.h>
#include     <errno.h>
#define DEV_FILE "/dev/2451_temperature"
float factor = 0.625;
short tmp = 0;
int main()
{
        int fd_dev=-1;
        int dat;
	char * ptr;
	char ht, lt, temp;
        printf("nanoPi driver Test\n");

        fd_dev = open(DEV_FILE,O_RDWR);
        if(fd_dev<0){
                printf("open device err\n");
                return 0;
        }


        while(1){
		read(fd_dev, &temp, sizeof(char));
		lt = temp;
		read(fd_dev, &temp, sizeof(char));
		ht = temp;
		printf("temperature: %d,%d \n", lt, ht);
        	sleep(1);
	}

        return 0;
}

