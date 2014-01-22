#include<stdio.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<inttypes.h>
#include<fcntl.h>
typedef long long hr_time_t;
main(){
int fd,i=0;
char buffer[4097];
        memset(buffer,1,4096);
        fd = open("/dev/zd0",O_RDWR,0666);
        if(fd<0){
        printf("fd=%d",fd);
        }
for(i=0;i<10000;i++){

        read(fd,buffer,4096);
}
for(i=0;i<100;i++){
        pwrite(fd,buffer,4096,20000*4096-i*4096);
}
        sleep(10);
/*backward access pattern */
for(i=0;i<100;i++){
        pread(fd,buffer,4096,20000*4096-i*4096);
}
}
~                                        
