#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int maxnum = 100;
const int maxint = 999999;

// 各数组都从下标1开始
int dist[maxnum];     // 表示当前点到源点的最短路径长度

int c[maxnum][maxnum];   // 记录图的两点间路径长度
int n, line;             // 图的结点数和路径数

// n -- n nodes
// v -- the source node
// dist[] -- the distance from the ith node to the source node
// prev[] -- the previous node of the ith node
// c[][] -- every two nodes' distance
void Dijkstra(int n, int v, int *dist, vector<int> *prev, int c[maxnum][maxnum])
{
    bool s[maxnum];    // 判断是否已存入该点到S集合中
    for(int i=1; i<=n; ++i)
    {
        dist[i] = c[v][i];
        s[i] = 0;     // 初始都未用过该点
        if(dist[i] < maxint)
            prev[i].push_back(v);
    }
    dist[v] = 0;
    s[v] = 1;
    
    // 依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    // 一旦S包含了所有V中顶点，dist就记录了从源点到所有其他顶点之间的最短路径长度
    // 注意是从第二个节点开始，第一个为源点
    for(int i=2; i<=n; ++i)
    {
        int tmp = maxint;
        int u = v;
        // 找出当前未使用的点j的dist[j]最小值
        for(int j=1; j<=n; ++j)
            if((!s[j]) && dist[j]<tmp)
            {
                u = j;              // u保存当前邻接点中距离最小的点的号码
                tmp = dist[j];
            }
        s[u] = 1;    // 表示u点已存入S集合中
        
        // 更新dist
        for(int j=1; j<=n; ++j)
            if((!s[j]) && c[u][j]<maxint)
            {
                int newdist = dist[u] + c[u][j];
                if(newdist <= dist[j])
                {
                    if (newdist < dist[j]) {
                        prev[j].clear();
                        dist[j] = newdist;
                    }
                    prev[j].push_back(u);
                }
            }
    }
}

// 查找从源点v到终点u的路径，并输出
void searchPath(vector<int> *prev, int v, int u, int sta[], int len) {
    if (u == v) {
        cout<<v;
        return ;
    }
    sta[len] = u;
    for (int i = 0 ; i < prev[u].size(); ++i ) {
        if (i > 0) {
            for (int j = len - 1  ; j >= 0 ; --j) {
                cout << " -> " << sta[j];
            }
            cout<<endl;
        }
        searchPath(prev, v, prev[u][i], sta, len + 1);
        cout << " -> " << u;
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    // 各数组都从下标1开始
    vector<int> prev[maxnum];     // 记录当前点的前一个结点
    // 输入结点数
    cin >> n;
    // 输入路径数
    cin >> line;
    int p, q, len;          // 输入p, q两点及其路径长度
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            c[i][j] = maxint;
    
    for(int i=1; i<=line; ++i)
    {
        cin >> p >> q >> len;
        if(len < c[p][q])       // 有重边
        {
            c[p][q] = len;      // p指向q
            c[q][p] = len;      // q指向p，这样表示无向图
        }
    }
    
    for(int i=1; i<=n; ++i)
        dist[i] = maxint;
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)
            printf("%8d", c[i][j]);
        printf("\n");
    }
    
    Dijkstra(n, 1, dist, prev, c);
    
    cout << "源点到最后一个顶点的最短路径长度: " << dist[n] << endl;
    cout << "源点到最后一个顶点的路径为: "<<endl;
    int sta[maxnum];
    searchPath(prev, 1, n, sta, 0);
}

/*
 
 5 8
 1 2 10
 1 4 20
 1 5 100
 2 3 10
 3 5 10
 4 3 10
 4 5 10
 2 5 20
 999999      10  999999      20     100
 10  999999      10  999999      20
 999999      10  999999      10      10
 20  999999      10  999999      10
 100      20      10      10  999999
 源点到最后一个顶点的最短路径长度: 30
 源点到最后一个顶点的路径为:
 1 -> 2 -> 5
 1 -> 2 -> 3 -> 5
 1 -> 4 -> 5请按任意键继续. . .
 */
