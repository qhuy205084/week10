/*
Chương trình sử dụng mảng các cấu trúc sử dụng sắp xếp chèn hoặc sắp xếp lựa chọn
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 100
typedef struct Address
{
    char name[MAX];
    char telephone_number[MAX];
    char email_address[MAX]; 
}Address;

Address A[MAX];

void input()
{
    FILE *f = fopen("input.txt","r");
    if(f == NULL)
    {
        printf("Can't open input file.\n");
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            fscanf(f,"%s %s %s\n", A[i].name, A[i].telephone_number, A[i].email_address );
        }
        fclose(f);
    }
}

void printinfor()
{   
    printf("Thong tin duoc dua vao la:\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%s %s %s\n", A[i].name, A[i].telephone_number, A[i].email_address );
    }
}
void output(Address A[], int n, char file[])
{
    FILE *fp = fopen(file,"w+");
    for(int i = 0; i < 10; i++)
        fprintf(fp,"%s %s %s\n", A[i].name, A[i].telephone_number, A[i].email_address);
    fclose(fp);
}

void insertsort(Address A[],int n)
{
    int i,j;
    Address B;
    for(i = 1; i < n; i++)
    {
        B = A[i];
        for(j = i - 1; j >= 0 && strcmp(B.name, A[j].name) < 0; j--)
            A[j+1] = A[j];
            A[j+1] = B;
    }
    printf("Danh sach duoc sap xep theo insertsort o file out_insertsort.txt!\n");
    output(A,n,"out_insertsort.txt");
}

void selectionsort(Address A[],int n)
{
    int i,j, min;
    Address tmp;
    for(i = 0; i < n - 1; i++)
    {
        min = i;
        for(j = i+1; j < n; j++)
        {
            if(strcmp(A[j].name, A[min].name) < 0)
                min = j;
            tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
        }

    }
    printf("Danh sach duoc sap xep theo insertsort o file out_selectionsort.txt!\n");
    output(A,n,"out_selectionsort.txt");
}

void main()
{
    input();
    printinfor();
    int choice;
    do
    {
        system("cls");
        printf("----------MENU----------\n");
        printf("1. Sap xep su dung sap xep chen.\n");
        printf("2. Sap xep su dung sap xep lua chon.\n");
        printf("3. Thoat.\n");
        printf("Moi ban chon menu:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insertsort(A,10);
                printf("Nhap phim bat ky de tiep tuc ...\n");
                getch();
                break;
            case 2:
                selectionsort(A,10);
                printf("Nhap phim bat ky de tiep tuc ...\n");
                getch();
                break;
            case 3:
                printf("Thoat.\n");
                printf("Nhap phim bat ky de tiep tuc ...\n");
                getch();
                break;
            default:
                printf("Nhan phim bat ky de tiep tuc ...\n");
                getch();
                break;
    
        }
    }while(choice!=3);

}