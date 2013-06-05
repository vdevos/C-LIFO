#include <sys/time.h>
#include <assert.h>

#include "lifo.h"

unsigned long long get_timestamp()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((unsigned long long)(tv.tv_sec) * 1000) + ((unsigned long long)(tv.tv_usec));
}


void start(void)
{
    push(get_timestamp());
}

unsigned long long stop(void)
{
    unsigned long long ts_end = get_timestamp();
    unsigned long long ts_start = popts();
    return ts_end - ts_start;
}

void function_one() {

    printf("Start of function_one\n");
    start();

    /* Do some stuff */

    unsigned long long duration = stop();
    printf("End of function_one - duration in microseconds: %llu\n", duration);
}

int main(int argc, char** argv)
{
    lifo_init();

    int i;
    for(i = 0; i < 10; i++) {
        function_one();
    }

    lifo_free();
    return 0;
}
