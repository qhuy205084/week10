// heap_sort

#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct Address
{
    char name[MAX];
    char telephone_number[MAX];
    char email_address[MAX];
}Address;

Address A[10];

void input()
{
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL)
    {
        printf("Can't open file input.txt!\n");
    }
    else
    {
        int i;
        for(i = 0; i < 10; i++)
        {
            fscanf(fp, "%s %s %s",A[i].name,A[i].telephone_number,A[i].email_address);
        }
    }
    fclose(fp);
}

void printinfor()
{
    printf("Thong tin duoc nhap vao la:\n");
    int i;
    for(i = 0; i < 10; i++)
    {
        printf("%s %s %s\n",A[i].name,A[i].telephone_number,A[i].email_address);
    }
}

void swap(Address *A, Address *B)
{
    Address tmp = *A;
    *A = *B;
    *B = tmp;
}

void heapify(Address A[], int n, int i)
{
    int L = 2*i+1;
    int R = 2*i+2;
    int max = i;
    if(L <= n && strcmp(A[L].name,A[i].name) > 0)
        max = L;
    if(R <= n && strcmp(A[R].name,A[max].name) > 0)
        max = R;
    if(max!=i)
    {
        swap(&A[i],&A[max]);
        heapify(A,n,max);
    }
}

void buildheap(Address A[], int n)
{
    int i;
    for(int i = n/2; i >= 0; i--)
        heapify(A,n,i);
}

void heapsort(Address A[], int n)
{
    buildheap(A,n);
    int i;
    for(i = n-1 ; i > 0; i--)
    {
        swap(&A[0],&A[i]);
        heapify(A,i-1,0);
    }
}

void output(Address A[], int n, char file[])
{
    FILE *fp = fopen(file,"w+");
    for(int i = 0; i < 10; i++)
        fprintf(fp,"%s %s %s\n", A[i].name, A[i].telephone_number, A[i].email_address);
    fclose(fp);
    printf("Thong tin da duoc sap xep o file %s!\n",file);
}

void main()
{
    input();
    printinfor();
    heapsort(A, 10);
    output(A, 10, "out_heapsort.txt");
}