/*************************************************************************
 > File Name: merge_sort.cc
 > Author: 周雨晨
 > Mail: 15917836@qq.com
 > Created Time: Mon 04 May 2015 21:11:12 CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#define SIZE 10
using namespace std;

void arr_init(int arr[],int len);
void arr_show(int arr[],int len);
void swap(int* a,int* b);
void mergearray(int arr[],int first,int mid,int last,int temp[]);
void mergesort(int arr[],int first,int last,int temp[]);
bool MergeSort(int arr[],int n);

int main()
{
    int arr[SIZE];
    arr_init(arr,SIZE);
    arr_show(arr,SIZE);
    MergeSort(arr,SIZE);
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

void mergearray(int arr[],int first,int mid,int last,int temp[])
{
    int i = first;
    int j = mid + 1;
    int k = 0;
    int m = mid;
    int n = last;

    while(i <= m && j <= n)
    {
        if(arr[i] < arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= m)
        temp[k++] = arr[i++];
    while(j <= n)
        temp[k++] = arr[j++];

    for(i=0;i<k;i++)
    {
        arr[first + i] = temp[i]; //将排序好的数组写回
    }
}

void mergesort(int arr[],int first,int last,int temp[])
{
    if(first < last)
    {
        int mid = (first + last)/2;
        mergesort(arr,first,mid,temp);
        mergesort(arr,mid+1,last,temp);
        mergearray(arr,first,mid,last,temp);
    }
}

bool MergeSort(int arr[],int n)
{
    int *p = new int[n];
    if(p == NULL)
        return false;
    mergesort(arr,0,n-1,p);
    delete[] p;
    return true;
}
