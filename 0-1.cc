/*************************************************************************
 > File Name: 0-1.cc
 > Author: 周雨晨
 > Mail: 15917836@qq.com
 > Created Time: Wed 06 May 2015 10:04:40 CST
 ************************************************************************/
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXN 1000
#define MAXC 100000
#define MAX(A,B) A>B?A:B

int V[MAXN],W[MAXN];
int d[MAXN][MAXC];

int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);

    int n,C;
    while(scanf("%d %d",&n,&C) != EOF)
    {
        for(int i=0;i<n;++i)
            scanf("%d %d",&V[i],&W[i]);
        for(int i=0;i<=n;++i)
        {
            for(int j=0;j<=C;++j)
            {
                d[i][j] = i==0? 0:d[i-1][j];
                if(i>0 && j>=V[i-1])
                    d[i][j] = MAX(d[i-1][j-V[i-1]] + W[i-1],d[i-1][j]);
            }
        }
        printf("%d\n",d[n][C]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
