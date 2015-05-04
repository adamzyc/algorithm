/*************************************************************************
 > File Name: binary_search.cc
 > Author: 周雨晨
 > Mail: 15917836@qq.com
 > Created Time: Sun 03 May 2015 23:36:09 CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#define SIZE 10
using namespace std;
void arr_init(int arr[],int len);
void arr_show(int arr[],int len);
void swap(int* a,int* b);
int binary_search(int arr[],int key,int min,int max);
int binary_search_iterative(int arr[],int key,int min,int max);

int main()
{
    int arr[SIZE] = {0,1,2,3,4,5,6,7,8,9};
    arr_show(arr,SIZE);
    int pos;
    std::cout << "binary_search:" << std::endl;
    pos = binary_search(arr,0,0,9);
    cout << pos << endl;
    pos = binary_search(arr,1,0,9);
    cout << pos << endl;
    pos = binary_search(arr,2,0,9);
    cout << pos << endl;
    pos = binary_search(arr,3,0,9);
    cout << pos << endl;
    pos = binary_search(arr,4,0,9);
    cout << pos << endl;
    pos = binary_search(arr,5,0,9);
    cout << pos << endl;
    pos = binary_search(arr,6,0,9);
    cout << pos << endl;
    std::cout << "binary_search_iterative:" << std::endl;
    pos = binary_search_iterative(arr,0,0,9);
    cout << pos << endl;
    pos = binary_search_iterative(arr,1,0,9);
    cout << pos << endl;
    pos = binary_search_iterative(arr,2,0,9);
    cout << pos << endl;
    pos = binary_search_iterative(arr,3,0,9);
    cout << pos << endl;
    pos = binary_search_iterative(arr,4,0,9);
    cout << pos << endl;
    pos = binary_search_iterative(arr,5,0,9);
    cout << pos << endl;
    pos = binary_search_iterative(arr,6,0,9);
    cout << pos << endl;
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

int binary_search(int arr[],int key,int min,int max)
{
    if(max < min)
        return -1;
    else {
        int mid = (min + max)/2;
        if(arr[mid] > key)
            return binary_search(arr,key,min,mid-1);
        else if(arr[mid] < key)
            return binary_search(arr,key,mid+1,max);
        else {
            return mid;
        }
    }
}

int binary_search_iterative(int arr[],int key,int min,int max)
{
    while(max >= min)
    {
        int mid = (min + max)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            min = min + 1;
        else {
            max = mid - 1;
        }
    }
    return -1;
}
