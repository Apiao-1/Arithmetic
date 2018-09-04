//1094 The Largest Generation（25)
#include <iostream>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstdio>
using namespace std;
int mark[101],de[101];
int n,m,tmp,k,a,root;
struct node{
    int depth;
    vector<int> child;
}p[101];

void bfs(){
    queue<int> que;
    que.push(root);
    while(!que.empty()){
        tmp = que.front();
        que.pop();
        de[p[tmp].depth]++;
        int len = p[tmp].child.size();
        for (int i = 0; i<len; i++) {
            p[p[tmp].child[i]].depth = p[tmp].depth+1;
            que.push(p[tmp].child[i]);
        }
        
    }
}

int main(){
    cin >> n>> m;
    for(int i = 0 ; i < m;i++){
        cin >> tmp;
        cin >> k;
        for(int j = 0;j < k;j++){
            cin >> a;
            p[tmp].child.push_back(a);
            mark[a] = 1;
        }
    }
    for(int i = 1 ; i <= n;i++){
        if (mark[i] == 0) {
            root = i;
            break;
        }
    }
    p[root].depth = 1;
    bfs();
    int i = 1,max = 0,flag = 0;
    while(de[i] > 0){
        if(de[i] > max){
            max= de[i];
            flag = i;
        }
        i++;
    }
    cout << max << " " << flag << endl;
    return 0;
}
