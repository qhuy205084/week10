#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getrandom(int min,int max){
    return min +(int)(rand()*(max-min+1.0)/(1.0+RAND_MAX));
}
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void InserttionSort(int a[], int n){
    int i,j;
    for(i=1;i<n;i++){
        j=i;
        while((j>0)&&(a[j]<a[j-1])){
            swap(&a[j],&a[j-1]);
            j--;
        }
    }
}
int main(){
    int a[500];
    int i;
    double time_use;
    clock_t start,end;
    for (i=0;i<500;i++){
        a[i]=getrandom(1,500);
    }
    for (i=0;i<500;i++){
        printf("%d ",a[i]);
    }
    start=clock();
    InserttionSort(a,500);
    end=clock();
    for (i=0;i<500;i++){
        printf("%d ",a[i]);
    }
    time_use=(double)(end-start)/CLOCKS_PER_SEC;
    printf("\nThoi gian chay :%f",time_use);
    printf("\n");
    return 0;
}