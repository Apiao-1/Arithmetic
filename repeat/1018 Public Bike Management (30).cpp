//1018 Public Bike Management (30) https://www.nowcoder.com/pat/5/problem/4324
//dijkstra（记录路径） + DFS
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;
int s[510],cost[510][510],n;
int Cmax,minTime;
vector<int> pre[510];
vector<int> minRoad,tmpRoad;
int minNeed,minBack;

int dij(int s,int e){
    int dist[n+1],tag[n+1];//注意这里n要+1，否则会报段错误
    int min = 99999,flag = 0;
    memset(tag, 0, sizeof(tag));
    for (int i = 0; i<=n; i++) {
        dist[i] = cost[s][i];
    }
    dist[0] = 0;//重要！
    for (int j = 0; j<=n; j++) {
        min = 99999;flag = -1;
        for (int i = 0; i<=n; i++) {
            if (!tag[i] && dist[i] < min) {
                min = dist[i];
                flag = i;
            }
        }
        if (flag == -1) {//若最小值未更新则表示算法已结束
            break;
        }
        tag[flag] = 1;
        for (int i = 0; i<=n; i++) {
            if (!tag[i]) {
                if (dist[flag] + cost[flag][i] < dist[i]) {
                    dist[i] = dist[flag] + cost[flag][i];
                    pre[i].clear();//记录路径
                    pre[i].push_back(flag);
                }else if (dist[flag] + cost[flag][i] == dist[i])//记录多条路径
                    pre[i].push_back(flag);
            }
        }
    }
    return dist[e];
}

void dfs(int cur){
    tmpRoad.push_back(cur);
    if (cur == 0) {
        int need=0,back=0;
        for (int i = tmpRoad.size()-1; i>=0; i--) {
            int id = tmpRoad[i];
            if (s[id] >= 0 ) {
                back += s[id];
            }else{
                if (back >= -s[id]) {
                    back += s[id];
                }else{
                    need -= back + s[id];
                    back = 0;
                }
            }
        }
        if (need < minNeed) {
            minNeed = need;
            minBack = back;
            minRoad = tmpRoad;
        }else if(need == minNeed && back < minBack){
            minBack = back;
            minRoad = tmpRoad;
        }
        tmpRoad.pop_back();
        return ;
    }
    for (int i = 0; i < pre[cur].size(); i++) {
        dfs(pre[cur][i]);
    }
    tmpRoad.pop_back();
}

int main(){
    int m,x,y,dest,i;
    while (cin >> Cmax >> n >> dest >> m) {
        for (i = 1; i<=n; i++) {
            cin >> s[i];
            s[i] -= Cmax/2;
        }
        //for (int i=0; i<m; i++) {
        //    for (int j=0; j<m; j++) {
        //        cost[i][j] = 99999;
        //    }
        //}
        //memset(cost, -1, sizeof(cost));//-1表示不可达
        minNeed = minBack = 99999;
        fill(cost[0], cost[0] + 510 * 510, 99999);//初始化为无穷大
        for (i = 0; i<m; i++) {
            cin >> x >> y;
            cin >> cost[x][y];
            cost[y][x] = cost[x][y];
        }
        minTime = dij(0,dest);//通过dijkstra算法求得最短路径长度
        dfs(dest);
        cout <<  minNeed << " ";
        for (i = minRoad.size()-1; i>0; i--) {
            cout << minRoad[i] << "->";
        }
        cout << minRoad[i] << " "<<minBack << endl;
        
    }
    return 0;
}
