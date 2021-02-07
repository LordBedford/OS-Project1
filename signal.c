#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

/* Part 1 - Step 2 to 4: Do your tricks here
 * Your goal must be to change the stack frame of caller (main function)
 * such that you get to the line after "r2 = *( (int *) 0 )"
 */
void segment_fault_handler(int signum) {

    printf("I am slain!\n");

    printf("%p\n", &signum);
    //(signum) = (&signum) + 0xffffd5d0 + 0x8;
    int* ptr = &signum;
    /*
    int i = 0;
    for (i=0; i<=0xf; i++) {
    	printf("Pointer int: %p\n", *(ptr+i));
    }
    */
    ptr += 0xf;
    //ptr = &ptr;
    /*
    while(ptr < 0xffffd6ac){
        ptr += 0x1;
    }
    */

    //0x5655557d
    //printf("%p\n", ptr);
    //printf("%x\n", *ptr);
    
    *ptr += 0x8;
    
    //int r2 = 0;
    //r2 = *( (int *) 0 );
    /*
     * Bad instruction length is 8 bytes
     */

    /* Implement Code Here */


}

int main(int argc, char *argv[]) {

    int r2 = 0;

    /* Part 1 - Step 1: Registering signal handler */
    /* Implement Code Here */
    signal(SIGSEGV,segment_fault_handler);
    r2 = *( (int *) 0 ); // This will generate segmentation fault

    printf("I live again!\n");

    return 0;
}