/*************************************************************************
 > File Name: heap_sort.cc
 > Author: 周雨晨
 > Mail: 15917836@qq.com
 > Created Time: Sun 03 May 2015 17:39:38 CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define SIZE 10
using namespace std;

void arr_init(int arr[],int len);
void arr_show(int arr[],int len);
void HeapAdjust(int arr[],int i,int length);
void HeapSort(int arr[],int length);
void swap(int* a,int* b);

int main()
{
    int arr[SIZE];
    arr_init(arr,SIZE);
    arr_show(arr,SIZE);
    HeapSort(arr,SIZE);
    arr_show(arr,SIZE);
    return 0;
}

void arr_init(int arr[],int len)
{
    srand((unsigned)(time(NULL)));
    for(int i = 0;i < len; ++i)
    {
        arr[i] = rand()%100;
    }
}

void arr_show(int arr[],int len)
{
    for(int i = 0;i < len;++i)
        printf("%2d ",arr[i]);
    printf("\n");
}

void swap(int* a,int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void HeapAdjust(int arr[],int i,int length)
{
    int nChild;
    int tmp;
    for(;2*i+1<length;i=nChild)
    {
        nChild = 2*i + 1;
        if(nChild < length-1 && arr[nChild + 1] > arr[nChild])
            ++nChild;
        if(arr[i] < arr[nChild])
            swap(&arr[i],&arr[nChild]);
        else break;
    }
}

void HeapSort(int arr[],int length)
{
    int i;
    for(i = length/2-1;i>=0;--i)
        HeapAdjust(arr,i,length);
    for(i = length-1;i>0;--i)
    {
        swap(&arr[i],&arr[0]);
        HeapAdjust(arr,0,i);
    }

}
