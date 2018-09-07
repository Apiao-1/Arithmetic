//1146 Topological Order（25)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
int e[1010][1010],du[1010],tag[1010];
vector<int> vec[1010];

int main()
{
    int n,m,a,b,tmp;
    cin >>n>>m;
    for(int i =0; i<m; i++)
    {
        scanf("%d%d",&a,&b);
        //        e[a][b] = 1;
        vec[a].push_back(b);
        du[b]++;//只统计入度
    }
    int k,flag = 1;
    scanf("%d",&k);
    for(int i = 0; i<k; i++)
    {
        int isPrint = 0;
        for(int j=1; j<=n; j++)
        {
            tag[j] = du[j];
        }
        for(int j =0; j<n; j++)
        {
            scanf("%d",&tmp);
            if(!isPrint)
            {
                if(tag[tmp] == 0)
                {
                    int len = vec[tmp].size();
                    for(int p = 0; p<len; p++)
                        tag[vec[tmp][p]]--;
                }
                else
                {
                    if(flag)
                    {
                        cout <<i;
                        flag = 0;
                    }
                    else cout << " " << i;
                    isPrint = 1;
                }
            }
        }
    }
    cout <<endl;
    return 0;
}
