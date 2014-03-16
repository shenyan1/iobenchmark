/* 测试共享内存，使用ipcs可以查看linux系统中所有的共享内存的信息。
 * 根据之前创建的共享内存的id，获得这个缓存的数据，并打印出来。
 */

#include<sys/shm.h>
#include<stdio.h>
main(){
 int id;
 id = 1048604;
 char *ptr = shmat(id,NULL,0);
 printf("ptr=%d",*ptr);
}
