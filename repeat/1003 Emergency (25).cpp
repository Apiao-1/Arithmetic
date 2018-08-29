//1003 Emergency (25) https://pintia.cn/problem-sets/994805342720868352/problems/994805523835109376
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;
int w[510],cost[510][510],n,start,endPoint,sum[510],num[510];

void dij(int s,int e){
    int dist[n+1],tag[n+1];//注意这里n要+1，否则会报段错误
    int min = 99999,flag = 0;
    memset(tag, 0, sizeof(tag));
    for (int i = 0; i<=n; i++) {
        dist[i] = cost[s][i];
    }
    sum[s] = w[s];
    num[s] = 1;
    dist[s] = 0;//重要！
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
                    sum[i] = sum[flag] + w[i];
                    num[i] = num[flag];
                }else if (dist[flag] + cost[flag][i] == dist[i]){//记录多条路径
                    num[i] += num[flag];
                    if (sum[flag] + w[i] > sum[i]) {
                        sum[i] = sum[flag] + w[i];
                    }
                }
            }
        }
    }
}

int main(){
    int m,x,y,i;
    while (cin >> n >> m >> start >> endPoint) {
        for (i = 0; i<n; i++) {
            cin >> w[i];
        }
        fill(cost[0], cost[0] + 510 * 510, 99999);//初始化为无穷大
        fill(num, num + 510, 0);
        fill(sum, sum + 510, 0);
        for (i = 0; i<m; i++) {
            cin >> x >> y;
            cin >> cost[x][y];
            cost[y][x] = cost[x][y];
        }
        dij(start,endPoint);//通过dijkstra算法求得最短路径长度
        cout << num[endPoint] << " " << sum[endPoint] << endl;
    }
    return 0;
}
