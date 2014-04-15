#include<pthread.h>
#include <sys/time.h>
#include <inttypes.h>
#include<assert.h>
#include<fcntl.h>
#define TEST_BLKSIZE (200<<10)
//随机从max_files个文件中顺序读取,每次200KB 读取1024次
typedef struct test_unit{
        int id;
        uint64_t fpos;
}test_unit_t;
int num_files=0;

void *lfs_test_read(void *arg){
        int i;
        int nums,size=200<<10;
        char *rbuffer,buf[6];
        nums = 1024;
        int id;
        id =(int)arg;
        uint64_t offset = 0;

        sprintf(buf,"f%d",id);

        rbuffer = malloc(size);
        memset(rbuffer,0,size);
        for(i=0;i<1024;i++){
                nums = pread(id,rbuffer,size,offset);
                assert(nums>0);
                offset += size;
        }
        free(rbuffer);

        return NULL;
}
#define max_files 689


void read_test_fini(){
}
uint64_t cur_usec(void)
{
    struct timeval __time;
    unsigned long long cur_usec;

    gettimeofday(&__time, NULL);
    cur_usec =  __time.tv_sec;
    cur_usec *= 1000000;
    cur_usec += __time.tv_usec;

    return cur_usec;
}

#define THREAD_NUMS 300ull
int readfd[THREAD_NUMS];
int main(){
        int i=0,randfd[THREAD_NUMS];
        uint64_t bw;
        int fd;
        char buf[10];
        pthread_t tids[THREAD_NUMS];
        srand(time(0));
        uint64_t stime,ctime;
        for(i=0;i<THREAD_NUMS;i++){
                randfd[i] = rand() % max_files;
                if(randfd[i]==0)
                        randfd[i]=1;
                sprintf(buf,"/shenyan/f%d",randfd[i]);
                printf("buf=%s\n",buf);
                fd = open(buf,O_RDWR,0666);
                if(fd<0)
                        assert(0);
                readfd[i]=fd;
        }
        srand(time(0));

        stime = cur_usec();
        for(i=0;i<THREAD_NUMS;i++){
                pthread_create(&tids[i],NULL,lfs_test_read,(void *)readfd[i]);
        }
        for(i=0;i<THREAD_NUMS;i++){
                pthread_join(tids[i],NULL);
        }

        ctime = cur_usec();
        bw = THREAD_NUMS*(200<<20);
        bw = bw / (ctime - stime);
        printf("bw=%"PRIu64"",bw);

        bw *= 1000000;
        bw = bw / 1024;
        printf("stat: bw = %"PRIu64" kB/s\n",bw);
        read_test_fini();
        return 1;
}
