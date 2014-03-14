#include<pthread.h>
int i=0;
void *lfs_test(void *arg){
pthread_t tid;
int a[1024];
a[0]=1;
//pthread_create(&tid,NULL,lfs_test,NULL);
        printf("lfs_test\n");
printf("i=%d\n,sizeof i=%d",i++,sizeof i );
        lfs_test(NULL);
//pthread_join(tid,NULL);
}
main(){
pthread_t tid;
pthread_create(&tid,NULL,lfs_test,NULL);
pthread_join(tid,NULL);
}
