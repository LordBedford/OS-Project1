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

double avg_time = 0;

void syscall_benchmark(){
    int num_of_calls = 3000;
    struct timeval current_time;
    gettimeofday(&current_time, NULL);
    printf("%ld", current_time.tv_usec);
    syscall(0);
    
}

int main(int argc, char *argv[]) {

    /* Implement Code Here */

    // Remember to place your final calculated average time
    // per system call into the avg_time variable

    printf("Average time per system call is %f microseconds\n", avg_time);
    syscall_benchmark();
    return 0;
}