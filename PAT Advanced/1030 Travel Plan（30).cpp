//1030 Travel Plan（30)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
using namespace std;
int n,m,s,e,cost[550][550],d[550][550],visit[550],dist[550],c[550];
vector<int> pre[550],ans;

void dij(){
    for (int i = 0; i<n; i++) {
        dist[i] = d[s][i];
        c[i] = cost[s][i];
    }
    dist[s] = 0;
    c[s] = 0;
//    visit[s] = 1;重要，此处这样加上的话，则最短路径的第二个点的pre节点就没有了
    for (int i = 0; i<n; i++) {
        int min = 99999,flag = -1;
        for (int j = 0; j<n; j++) {
            if (!visit[j] && dist[j] < min) {
                min = dist[j];
                flag = j;
            }
        }
        if (flag == -1) {
            break;
        }
        visit[flag] = 1;
        for (int i = 0; i<n; i++) {
            if (!visit[i] && dist[flag] + d[flag][i] <dist[i]) {
                dist[i] = dist[flag] + d[flag][i];
                c[i] = c[flag] + cost[flag][i];
                pre[i].clear();
                pre[i].push_back(flag);
            }else if(!visit[i] && dist[flag] + d[flag][i] == dist[i]){
                if (c[flag] + cost[flag][i] < c[i]) {
                    c[i] = c[flag] + cost[flag][i];
                    pre[i].clear();
                    pre[i].push_back(flag);
                }
            }
        }
    }
    
}

void dfs(int id){
    if (id == s) {
        ans.push_back(id);
        return ;
    }
    int len = pre[id].size();
    for (int i = 0; i< len; i++) {
        dfs(pre[id][i]);
    }
    ans.push_back(id);
}

int main() {
    cin >> n >> m >> s >> e;
    int i,tmp1,tmp2,a,b;
    fill(cost[0], cost[0] + 550*550, 99999);
    fill(d[0], d[0] + 550*550, 99999);
    for (i = 0; i<m; i++) {
        cin >> a >> b;
        cin >> tmp1 >> tmp2;
        if (d[a][b] == 0 || tmp1 < d[a][b]) {
            d[a][b] = tmp1;
            cost[a][b] = tmp2;
        }else if (tmp1 == d[a][b]) {
            if (tmp2 < cost[a][b]) {
                cost[a][b] = tmp2;
            }
        }
        d[b][a] = d[a][b];
        cost[b][a] = cost[a][b];
    }
    dij();
    dfs(e);
    int len = ans.size();
    cout << s <<" " ;
    for (i = 0; i<len; i++) {
            cout <<ans[i] << " ";
    }
    cout << dist[e] <<" "<<c[e] <<endl;
    return 0;
}

