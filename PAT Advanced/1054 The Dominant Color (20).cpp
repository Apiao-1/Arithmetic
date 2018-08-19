//1054 The Dominant Color (20) https://pintia.cn/problem-sets/994805342720868352/problems/994805422639136768
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
using namespace std;

int main(){
    map<int, int> sto;
    int n,m,tmp;
    scanf("%d%d",&n,&m);
    for (int i = 0; i<m; i++) {
        for (int j = 0; j<n; j++) {
            scanf("%d",&tmp);
            sto[tmp]++;
        }
    }
    map<int, int> ::iterator itor = sto.begin();
    int max = 0,flag = 0;
    for (; itor != sto.end(); itor++) {
        if (itor->second > max) {
            max = itor->second;
            flag = itor -> first;
        }
    }
    printf("%d\n",flag);
    return 0;
}
