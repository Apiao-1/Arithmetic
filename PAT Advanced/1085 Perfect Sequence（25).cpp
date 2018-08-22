//1085 Perfect Sequence（25)https://pintia.cn/problem-sets/994805342720868352/problems/994805381845336064
//注意数据大小，n<10^9用long long型，此题dfs超时，用two points的思想求解

#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;
int a[100010],maxl = 0;
long long p;

void dfs(int s, int e, int len){
    if (p * a[s]>= a[e]) {
        if (len > maxl) {
            maxl = len;
        }
        return ;
    }
    dfs(s+1, e, len-1);
    dfs(s, e-1, len-1);
}

int main(){
    int n;
    scanf("%d%lld",&n,&p);
    for (int i = 0; i< n; i++) {
        scanf("%d",&a[i]);
    }
    sort(a, a+n);
    int ans = 0,len = 0;

//    dfs(0,n-1,len);
    for (int i = 0; i< n;i++) {
        for (int j = i + ans; j<n; j++) {
            if (p * a[i]>= a[j]) {
                len = j-i+1;
                if (len > ans) {
                    ans = len;
                }
            }else
                break;
        }
    }
    cout << ans << endl;
    return 0;
}

