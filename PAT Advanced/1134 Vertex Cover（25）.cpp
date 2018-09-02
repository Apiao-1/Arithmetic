//1134 Vertex Cover（25）
//传统的邻接表邻接图的方式去做都会超时，比较巧妙此题保存的是一条边的两个节点，之后在set查询的节点集合中，依次用find查找每条边的两个节点
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
using namespace std;

struct edge{
    int a;
    int b;
}edges[10010];

int main()
{
    int N,M,node;
    while(cin >> N >> M)
    {
        for(int i = 0; i < M; i++)
        {
            cin >> edges[i].a >>edges[i].b;
        }
        int K;
        cin >> K;
        for(int i = 0; i < K; i++)
        {
            int Nv;
            cin >> Nv;
            set<int> nodes;
            for(int j = 0; j < Nv; j++)
            {
                cin >> node;
                nodes.insert(node);
            }
            bool isCovered = true;
            for(int v = 0; v < M; v++)
            {
                if(nodes.find(edges[v].a) == nodes.end() && nodes.find(edges[v].b) == nodes.end())
                {
                    isCovered = false;
                    break;
                }
            }
            if(isCovered)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}
