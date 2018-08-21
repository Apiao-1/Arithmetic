//1046 Shortest Distance (20) https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424
//用sum数组进行累加，顺时针情况两点见的值通过对应sum相减的方式处理，逆时针的话通过整个环的总和减去顺时针的就好
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
#include <set>
using namespace std;


int main(){
    int n,m;
    scanf("%d",&n);
    int a[n+10],sum1[n+10],tmp = 0;
    memset(sum1, 0, sizeof(sum1));
    for (int i = 0;i<n; i++) {
        scanf("%d",&a[i]);
        tmp += a[i];
        sum1[i+2] = tmp;
    }
    scanf("%d",&m);
    int s,e;
    for (int i = 0; i<m; i++) {
        scanf("%d%d",&s,&e);
        if (s > e) {
            swap(s, e);
        }
        int ans = min(tmp - (sum1[e] - sum1[s]),sum1[e] - sum1[s]);
        printf("%d\n",ans);
    }

    
    return 0;
}

