//1131 Subway Map（30)
//第一种写法还是有问题，递归里的内容太复杂不推荐，详见第二种
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <string.h>
//#include <algorithm>
//#include <math.h>
//#include <vector>
//#include <map>
//#include <set>
//#include <cstdio>
//using namespace std;
//int sta,en,minNode = 99999,minTrens=99999,tmp,mark[10010],line[10010][10010],nextStation;
//vector<int> s[10010];
//
//struct node{
//    int s,e,l;
//};
//vector<node> res,ans;
//
//void dfs(int curStation,int cntStation,int lineCnt,int pre,int transBegin)
//{
//    if(mark[curStation] || cntStation > minNode) return ;
//    mark[curStation] = 1;
//    if(curStation == en)
//    {
//        res.push_back(node{transBegin,curStation,line[transBegin][curStation]});
//        if(cntStation < minNode)
//        {
//            minNode = cntStation;
//            minTrens = lineCnt;
//            ans.clear();
//            ans = res;
//        }else if(cntStation == minNode){
//            if(lineCnt < minTrens){
//                minTrens = lineCnt;
//                ans.clear();
//                ans = res;
//            }
//        }
//        mark[curStation] = 0;
//        res.pop_back();
//        return ;
//    }
//    int len = s[curStation].size();
//    for(int i = 0; i<len; i++)
//    {
//        nextStation = s[curStation][i];
//        if(!mark[nextStation])
//        {
//            if(line[nextStation][curStation] != line[pre][curStation]){
//                res.push_back(node{transBegin,curStation,line[pre][curStation]});
//                dfs(nextStation,cntStation+1,lineCnt+1,curStation,curStation);
//                res.pop_back();
//            }
//            else
//                dfs(nextStation,cntStation+1,lineCnt,curStation,transBegin);
//        }
//    }
//    mark[curStation] = 0;
//
//}
//
//int main()
//{
//    int n,m,tmp,pre;
//    scanf("%d",&n);
//    for(int i = 1; i<=n; i++)
//    {
//        scanf("%d",&m);
//        cin >> pre;
//        for(int j = 1; j<m; j++)
//        {
//            cin >> tmp;
//            s[tmp].push_back(pre);
//            s[pre].push_back(tmp);
//            line[tmp][pre] = line[pre][tmp] = line[pre][pre] = i;//标记两个站点之间的线路
//            pre = tmp;
//        }
//    }
//    int q;
//    cin >> q;
//    for(int i =0; i<q; i++)
//    {
//        cin >> sta >> en;
//        ans.clear();
//        res.clear();
//        minNode = 99999;
//        minTrens=99999;
//        fill(mark,mark+10010,0);
//
//        dfs(sta,0,0,sta,sta);
//
//        printf("%d\n",minNode);
//        int len = ans.size();
//        for(int i=0;i<len;i++)
//            printf("Take Line#%d from %d to %d.\n",ans[i].l,ans[i].s,ans[i].e);
//    }
//    return 0;
//}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<int>> v(10000);
int visit[10000], minCnt, minTransfer, start, end1;
unordered_map<int, int> line;//line[10000][10000]存储的方式会导致一个测试点内存超限，固采用unordered_map存储，前四位存储第一个线路，后四位存储第二个线路
vector<int> path, tempPath;
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]*10000+a[i]] != preLine) cnt++;
        preLine = line[a[i-1]*10000+a[i]];
    }
    return cnt;
}
void dfs(int node, int cnt) {
    if (node == end1 && (cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer))) {
        minCnt = cnt;
        minTransfer = transferCnt(tempPath);
        path = tempPath;
    }
    if (node == end1) return;
//    visit[node] = 1;进入下一层再标记为已访问也可以的
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], cnt + 1);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
//    visit[node] = 0;
}
int main() {
    int n, m, k, pre, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre*10000+temp] = line[temp*10000+pre] = i + 1;
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &start, &end1);
        minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        tempPath.push_back(start);
        visit[start] = 1;
        dfs(start, 0);
        visit[start] = 0;
        printf("%d\n", minCnt);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]*10000+path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]*10000+path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, end1);
    }
    return 0;
}
