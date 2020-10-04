#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void fill_rand(int n, double* A)
{
	for(int i=0;i<n;i++)
		A[i]=2.0;
}

int Sum_array(int n,double* A)
{
	double sum=0.0;
	for(int i=0;i<n;i++)
		sum+=A[i];
	return sum;
}
int main()
{
	int N=10;
double *A, sum, runtime; int numthreads, flag = 0;
A = ( (double *)malloc(N*sizeof(double)));
runtime=omp_get_wtime();
#pragma omp parallel sections
{
#pragma omp section
{
fill_rand(N, A);
#pragma omp flush
flag = 1;
#pragma omp flush (flag)
}
#pragma omp section
{
#pragma omp flush (flag)
while(flag!=1){
#pragma omp flush (flag)
}
#pragma omp flush
sum = Sum_array(N,A);}
}
runtime=omp_get_wtime()-runtime;
printf("In %lf seconds the sum is %lf \n",runtime,sum);
}
