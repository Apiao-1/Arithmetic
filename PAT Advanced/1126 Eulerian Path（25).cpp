//1126 Eulerian Path（25)
/*/
 如何判断图是否有欧拉回路或者欧拉路径？
 无向图：因为欧拉路径中，除了起点与终点以外，任意点的“进”“出”次数相等，所以除了两个点为奇点（度数为奇数的点）（终点和起点）以外，其它点的度数均为偶数。
 如果是欧拉回路，奇点的个数应该为0。
 有向图：欧拉路径中，最多只有两个点的入度不等于出度。起点出度比入度大1，终点入度比出度大1。
 如果是欧拉回路，所有点的 入度=出度 。
 /*/
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
int e[510][510],root[510],du[510];

int findroot(int node){
    int tmp = node,a;
    while(root[node] != 0){
        node = root[node];
    }
    while(root[tmp] != 0){
        a = root[tmp];
        root[tmp] = node;
        tmp = a;
    }
    return node;
}

int main(){
    int n,m,a,b,x,y;
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
        du[a]++;
        du[b]++;
        x = findroot(a);
        y = findroot(b);
        if (x != y) {
            root[x] = y;
        }
    }
    int flag=0,cnt=0;
    for (int i = 1; i<=n; i++) {
        if (root[i] == 0) {
            cnt++;
        }
    }
    for (int i = 1; i<=n; i++) {
        if (du[i] % 2 != 0) {
            flag++;
        }
        if (i == 1) {
            cout << du[i];
        }else
            cout << " " << du[i];
    }
    cout << endl;
    if (cnt == 1) {
        if (flag == 2) {
            cout << "Semi-Eulerian" << endl;
        }else if(flag == 0)
            cout << "Eulerian" << endl;
        else
            cout << "Non-Eulerian" << endl;
    }else
        cout << "Non-Eulerian" << endl;
}
