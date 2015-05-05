/*************************************************************************
 > File Name: kmp.cc
 > Author: 周雨晨
 > Mail: 15917836@qq.com
 > Created Time: Tue 05 May 2015 20:17:42 CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

void GetNext(const char *p,int next[])
{
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while(j < pLen - 1)
    {
        if(k==-1 || p[j] == p[k])
        {
            ++k;
            ++j;
            if(p[j] !=p[k])
                next[j] = k;
            else {
                next[j] = next[k];
            }
        }
        else {
            k = next[k];
        }
    }
}

int KmpSearch(const char* s,const char* p,int next[])
{
    int i = 0;
    int j = 0;
    int sLen = strlen(s);
    int pLen = strlen(p);
    while(i < sLen && j < pLen)
    {
        if(j == -1 || s[i] == p[j])
        {
            ++i;
            ++j;
        }
        else {
            j = next[j];
        }
    }
    if(j == pLen)
        return i-j;
    else {
        return -1;
    }
}

int main()
{
    const char* s = "abcdabcdabde";
    const char* p = "abcdabd";
    int len = strlen(p);
    int next[len];
    GetNext(p,next);
    std::cout << s << std::endl;
    std::cout << p << std::endl;
    int ret = KmpSearch(s,p,next);
    std::cout << "ret: " << ret << std::endl;
    return 0;
}
