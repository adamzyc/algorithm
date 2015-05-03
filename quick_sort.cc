/*************************************************************************
 > File Name: quick_sort.cc
 > Author: 周雨晨
 > Mail: 15917836@qq.com
 > Created Time: Sat 02 May 2015 23:37:41 CST
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
void quick_sort(int arr[],int begin,int end);
void swap(int* a,int* b);

int main()
{
    int arr[SIZE];
    arr_init(arr,SIZE);
    arr_show(arr,SIZE);
    quick_sort(arr,0,SIZE-1);
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

void quick_sort(int arr[],int begin,int end)
{
    if(begin > end)
        return ;
    int i = begin;
    int j = end;
    int temp = arr[begin];
    while(i<j)
    {
        while(i<j && arr[j] >= temp)
            j--;
        while(i<j && arr[i] <= temp)
            i++;
        swap(&arr[i],&arr[j]);
    }
    arr[begin] = arr[i];
    arr[i] = temp;
    quick_sort(arr,begin,i-1);
    quick_sort(arr,i+1,end);
}

void swap(int* a,int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
