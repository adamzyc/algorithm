/*************************************************************************
 > File Name: lcs.cc
 > Author: 周雨晨
 > Mail: 15917836@qq.com
 > Created Time: Tue 05 May 2015 08:40:17 CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
enum type {
    err,left1,up,leftup
}x;

int lcs_length(int a[10][10],int b[10][10],const char* str1,const char* str2);
void print_lcs(int b[10][10],const char* str1,int length1,int length2);
void print_arr(int a[10][10]);

int main()
{
    const char* str1 = "abcdefg";
    const char* str2 = "acdf";
    int a[10][10];
    int b[10][10];
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int ret = lcs_length(a,b,str1,str2);
    std::cout << "ret: " << ret << std::endl;
    print_lcs(b,str1,len1,len2);
    cout << endl;
    print_arr(a);
    return 0;
}

int lcs_length(int a[10][10],int b[10][10],const char* str1,const char* str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i,j;
    for(int p = 0;p<10;++p)
        for(int q = 0;q< 10 ;++q)
            a[p][q] = 0;
    for(i=1;i<len1+1;++i)
    {
        for(j=1;j<len2+1;++j)
        {
            if(str1[i-1] == str2[j-1])
            {
                a[i][j] = a[i-1][j-1] + 1;
                b[i][j] = leftup;
            }
            else if (a[i-1][j] >= a[i][j-1]) {
                a[i][j] = a[i-1][j];
                b[i][j] = up;
            }
            else {
                a[i][j] = a[i][j-1];
                b[i][j] = left1;
            }
        }
    }
    return a[i-1][j-1];
}

void print_arr(int arr[10][10])
{
    for(int i = 0;i<10;++i)
    {
        for(int j = 0;j < 10;++j)
        {
            printf("%2d",arr[i][j]);
        }
        std::cout << std::endl;
    }
}

void print_lcs(int b[10][10],const char* str1,int i,int j)
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == leftup)
    {
        print_lcs(b,str1,i-1,j-1);
        cout << str1[i-1];
    }
    else if(b[i][j] == up)
        print_lcs(b,str1,i-1,j);
    else {
        print_lcs(b,str1,i,j-1);
    }
}
