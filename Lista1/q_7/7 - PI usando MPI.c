#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>


int main(){
    long long n;

    scanf("%lld",n);
    
    double L = 1.0 / n;
    double sum = 0.0;
        

    for(long long  i = 0; i <= n; i+){
        double x = (i + 0.5) * L;
        sum += 4.0 / (1.0 + x * x);
    }
}