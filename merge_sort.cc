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
using namespace std;

void arr_init(int arr[],int len);
void arr_show(int arr[],int len);
void swap(int* a,int* b);


int main()
{

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
