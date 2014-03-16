/*共享内存的服务端的程序，该程序向系统申请一个100000B的空间，并向这个缓冲区写数据。
 */
#include<stdio.h>
#include<sys/shm.h>
#define SHM_SIZE 100000
main(){
int id;
char *ptr;
if((id = shmget(IPC_PRIVATE,SHM_SIZE,(SHM_R|SHM_W|IPC_CREAT)))<0){
        perror("shmget error\n");
}
        printf("id=%d\n",id);
    ptr = shmat(id, NULL, 0);
    if(ptr == -1){
        perror("shmat error\n");
    }
    *ptr=1;
    printf("id=%d ptr=%d",id,ptr);
}
