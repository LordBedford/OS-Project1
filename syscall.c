/* syscall.c
 *
 * Group Members Names and NetIDs:
 *   1.
 *   2.
 *
 * ILab Machine Tested on:
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>                                                                                
#include <sys/syscall.h>
#include <unistd.h>

double avg_time = 0;

void syscall_benchmark(){
    int num_of_calls = 10000;
    int i =0;
    double total_time = 0;
    for(;i<num_of_calls;i++)
    {
        struct timeval start;
        struct timeval end;
        gettimeofday(&start, NULL);
        syscall(5);
         gettimeofday(&end, NULL);
        total_time = total_time + (end.tv_usec - start.tv_usec);
    }
    avg_time = total_time /num_of_calls;
}

int main(int argc, char *argv[]) {

    /* Implement Code Here */

    // Remember to place your final calculated average time
    // per system call into the avg_time variable
    syscall_benchmark();
    printf("Average time per system call is %f microseconds\n", avg_time);
    return 0;
}