//1091 Acute Stroke（30) https://www.nowcoder.com/pat/5/problem/4317
//BFS或DFS都可以，图的遍历
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
int n,m,l,t,ans = 0;
int cnt = 0;
int a[1300][130][65],visit[1300][130][65];
int dir[3][6] = {
    {1,-1,0,0,0,0},
    {0,0,1,-1,0,0},
    {0,0,0,0,1,-1}
};

struct node{
    int x,y,z;
}tmp,now;

queue<node> q;

void bfs(){
    while (!q.empty()) {
        now = q.front();
        q.pop();
        visit[now.x][now.y][now.z] = 1;
//        cout <<now.x << now.y << now.z << endl;
        cnt++;
        for (int i = 0; i<6; i++) {
            tmp.x = now.x + dir[0][i];
            tmp.y = now.y + dir[1][i];
            tmp.z = now.z + dir[2][i];
            if (tmp.x >= m || tmp.y >= n || tmp.z >= l ||tmp.x <0||tmp.y <0||tmp.z <0 ||visit[tmp.x][tmp.y][tmp.z] == 1 || a[tmp.x][tmp.y][tmp.z] == 0) {//地图边界注意添加小于0的情况
                continue;
            }
            q.push(tmp);
            visit[tmp.x][tmp.y][tmp.z] = 1;//此处需注意在如队列时就要把visit进行标记，否则会出现因为该点还未访问到造成重复入队的情况
        }
    }
    if (cnt >= t) {
        ans += cnt;
    }
}

void dfs(int x,int y,int z){
//    cout << x << y<<z << endl;
    visit[x][y][z] = 1;
    cnt++;
    for (int i = 0; i<6; i++) {
        int A = x + dir[0][i];
        int b = y + dir[1][i];
        int c = z + dir[2][i];
        if (A >= m || b >= n || c >= l ||A <0||b <0||c <0 ||visit[A][b][c] == 1 || a[A][b][c] == 0) {//地图边界注意添加小于0的情况
            continue;
        }
        visit[A][b][c] = 1;
        dfs(x + dir[0][i], y + dir[1][i], z + dir[2][i]);
    }
}

int main(){
    scanf("%d%d%d%d",&m,&n,&l,&t);
    for (int k = 0;k<l; k++) {
        for (int i = 0;i<m; i++) {
            for (int j = 0;j<n; j++) {
                scanf("%d",&a[i][j][k]);
            }
        }
    }
    for (int k = 0;k<l; k++) {
        for (int i = 0;i<m; i++) {
            for (int j = 0;j<n; j++) {
                if(visit[i][j][k] ==0 && a[i][j][k] == 1){
//                    tmp.x = i;
//                    tmp.y = j;
//                    tmp.z = k;
//                    cnt = 0;
//                    q.push(tmp);
//                    bfs();
                    cnt = 0;
                    dfs(i,j,k);
                    if (cnt >= t) {
                        ans += cnt;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    
    return 0;
}
