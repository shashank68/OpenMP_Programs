#include<stdio.h>
#include "omp.h" /* OpenMP compiler directives, APIs are declared here */
void printHello(threadID)
{
printf(" helloworld(%d)\n ", threadID);
}

void main()
{
/* Parallel region begins here */
#pragma omp parallel
{
int ID = omp_get_thread_num();
printHello(ID);
}
}
