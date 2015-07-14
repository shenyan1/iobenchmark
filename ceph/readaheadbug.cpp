#include<iostream>
#include<pthread.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
using namespace std;
int fd;
class A{
public:
A(){
   cout<<"begin"<<endl;
}

virtual ~A(){

   cout<<"delete"<<endl;
}
};
#define max_thread_count 1000
void* read_thread(void*)
{
  int size=1024*1024*1024;
  char *buffer=(char *)malloc(size);
  cout<<"hellow"<<endl;
  int ret= read(fd,buffer,size);
  cout<<"READ finished"<<ret<<endl;
  return 0;
}
void* close_thread(void*)
{
  sleep(2);
  cout<<"going to close"<<endl;
  int ret=close(fd);
  cout<<"finish close"<<ret<<endl;
  return 0;
}
main()
{
int f,i;
char buf[20];
pthread_mutex_t m[max_thread_count];
pthread_t tid[max_thread_count];

fd = open("/data/sy2/ceph-dokan1.log",O_RDWR,0666);
if(fd<0){
   printf("error");
   return 0;
}
pthread_create(&tid[0],0,read_thread,0);
pthread_create(&tid[1],0,close_thread,0);

 for(i=0;i<2;i++){
    pthread_join(tid[i],NULL);
}
}
