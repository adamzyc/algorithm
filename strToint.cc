/*************************************************************************
  > File Name: strToint.cc
  > Author: 周雨晨
  > Mail: 15917836@qq.com
  > Created Time: Wed 06 May 2015 10:51:29 CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

long long int strToint(const char* str);

int main()
{
    const char* str1 = "123456";
    const char* str2 = "-123456";
    const char* str3 = "+123789";
    const char* str4 = "10522545459";
    const char* str5 = "+10522545459";
    const char* str6 = "-10522545459";
    const char* str7 = "hello";

    cout << "str1: " << str1 << " = num: " << strToint(str1) << endl;
    cout << "str2: " << str2 << " = num: " << strToint(str2) << endl;
    cout << "str3: " << str3 << " = num: " << strToint(str3) << endl;
    cout << "str4: " << str4 << " = num: " << strToint(str4) << endl;
    cout << "str5: " << str5 << " = num: " << strToint(str5) << endl;
    cout << "str6: " << str6 << " = num: " << strToint(str6) << endl;
    cout << "str7: " << str7 << " = num: " << strToint(str7) << endl;

    return 0;
}

long long int strToint(const char* str)
{
    long long int num = 0;
    int len = strlen(str);
    if(!isdigit(str[0]))
    {
        if(str[0] == '-' || str[0] == '+')
        {
            cout << str[0] ;
            return strToint(&str[1]);
        }
        else {
            return -1;
        }
    }
    for(int i=0;i<len;++i)
    {
        int tmp = str[i]-'0';
        num = num + tmp;
        num = num * 10;
    }
    return num/10;
}

