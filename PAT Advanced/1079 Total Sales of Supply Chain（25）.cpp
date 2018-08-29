//1079 Total Sales of Supply Chain（25）https://pintia.cn/problem-sets/994805342720868352/problems/994805410555346944
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
double price,r,sum;

struct node{
    double r;
    vector<int> child;
}tree[100010];

int w[100010];

void dfs(int id,int depth){
    int len = tree[id].child.size();
    tree[id].r = pow(r,depth);
    if (len == 0) {
        sum += w[id]*tree[id].r*price;
    }else{
        for (int i =0; i<len; i++) {
            dfs(tree[id].child[i], depth+1);
        }
    }
    
    
}

int main() {
    int n,m,tmp;
    scanf("%d%lf%lf",&n,&price,&r);
    r = 1 + r/100;
    for (int i = 0; i<n; i++) {
        scanf("%d",&m);
        if (m == 0) {
            scanf("%d",&w[i]);
        }
        for (int j = 0; j<m; j++) {
            scanf("%d",&tmp);
            tree[i].child.push_back(tmp);
        }
    }
    dfs(0,0);
    printf("%.1lf\n",sum);
    return 0;
}


