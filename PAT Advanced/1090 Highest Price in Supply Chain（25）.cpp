//1090 Highest Price in Supply Chain（25）
//dfs+树的遍历
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;
int maxD = 0,cnt =0;

struct node{
    int rate;
    vector<int> child;
}a[100010];

void dfs(int root,int depth){
    if (depth > maxD) {
        maxD = depth;
        cnt = 1;
    }else if (depth == maxD)
        cnt++;
    int len = a[root].child.size();
    a[root].rate = depth;
    for (int i = 0; i < len ; i++) {
        dfs(a[root].child[i], depth+1);
    }
}
int main(){
    double n,price,r;
    int id,root;
    cin >> n >> price >> r;
    for (int i= 0; i<n; i++) {
        cin >> id;
        if (id == -1) {
            root = i;
            continue;
        }
        a[id].child.push_back(i);
    }
    dfs(root,0);
    printf("%.2lf %d\n",price*pow(1+r/100, maxD),cnt);
    return 0;
}
