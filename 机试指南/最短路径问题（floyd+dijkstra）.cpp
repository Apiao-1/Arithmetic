
//https://www.nowcoder.com/practice/e372b623d0874ce2915c663d881a3ff2?tpId=40&tqId=21483&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <cstring>
using namespace std;

struct edge{
    double val;
    double cost;
} edge[1001][1001];

struct edge dist[1001];
int n,start,fin;//村庄数


void floyd(){
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            for (int k = 1; k <=n; k++) {//加入第k号节点
                if (edge[i][k].val == 99999 || edge[k][j].val == 99999) {
                    continue;
                }
                if (edge[i][k].val+edge[k][j].val < edge[i][j].val) {
                    edge[i][j].val = edge[i][k].val+edge[k][j].val;
                    edge[i][j].cost = edge[i][k].cost+edge[k][j].cost;
                }else if(edge[i][k].val+edge[k][j].val == edge[i][j].val){
                    if(edge[i][k].cost+edge[k][j].cost < edge[i][j].cost){
                        //                        edge[i][j].val = edge[i][k].val+edge[k][j].val;
                        edge[i][j].cost = edge[i][k].cost+edge[k][j].cost;
                    }
                }
            }
        }
    }
    
}

void dijkstra(){
    int mark[n+1],flag=0;//标记矩阵,1代表已是最小值
    memset(mark, 0, sizeof(mark));
    for (int i = 1; i <= n; i++) {//初始化dist矩阵
        dist[i].val = edge[start][i].val;
        dist[i].cost = edge[start][i].cost;
    }
    dist[start].val = 0;
    dist[start].cost = 0;
    mark[start] = 1;
    struct edge min;
    min.val = min.cost = 99999;
    for (int k = 1; k <n; k++) {
        //找当前dist数组的最小值；
        min.val = min.cost = 99999;//必须每次重设最小值，重点！！！
        for (int j = 1; j <=n; j++) {
            if (mark[j])
                continue;
            if (dist[j].val < min.val) {
                min.val = dist[j].val;
                min.cost = dist[j].cost;
                flag = j;
            }else if(dist[j].val == min.val)
                if (dist[j].cost < min.cost) {
                    min.cost = dist[j].cost;
                    flag = j;
                }
        }
        mark[flag] = 1;//确认该点已为最小值
        //找到最小值后，更新dist
        for (int i = 1; i <=n; i++) {
            if (mark[i])
                continue;
            if (dist[i].val > dist[flag].val + edge[flag][i].val) {
                dist[i].val = dist[flag].val + edge[flag][i].val;
                dist[i].cost = dist[flag].cost + edge[flag][i].cost;
            }else if( dist[i].val == dist[flag].val + edge[flag][i].val)
                dist[i].cost = (dist[flag].cost + edge[flag][i].cost > dist[i].cost) ? dist[i].cost:dist[flag].cost + edge[flag][i].cost;
        }
    }
//    for (int i = 1; i <= n; i++) {
//        cout << dist[i].val << " " << dist[i].cost << endl;
//    }
    
}

int main(){
    int m,a,b,cost,val;
    while (cin >> n >> m) {
        if (!n && !m) {
            break;
        }
        for (int i = 1; i<=n; i++) {
            for (int j = 1; j <=n; j++) {
                edge[i][j].val = 99999;//初始化邻接矩阵
                edge[i][j].cost = 99999;
            }
        }
        //输入时注意陷阱，说是无向图但同两点间存在多条路径，需判断
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            cin >> val >> cost ;
            if (edge[a][b].val > val) {
                edge[a][b].val = edge[b][a].val =  val;
                edge[a][b].cost = edge[b][a].cost = cost;
            }else if (edge[a][b].val == val && edge[a][b].cost > cost)
                edge[a][b].cost = edge[b][a].cost = cost;
        }
        
//                floyd(); //Floyd算法,全源最短路径，O(n^3)
        cin >> start >> fin;
//        for (int i = 1; i<=n; i++) {
//            cout << edge[start][i].val << " "<< edge[start][i].cost << endl;
//        }
//        cout << edge[start][fin].val <<" "<< edge[start][fin].cost << endl;
        
        dijkstra();
        cout << dist[fin].val << " " << dist[fin].cost << endl;
        
    }
    
    return 0;
}
