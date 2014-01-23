#include <sys/time.h>
/* get current usec
 */
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
