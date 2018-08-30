//1076 Forwards on Weibo（30) https://pintia.cn/problem-sets/994805342720868352/problems/994805392092020736
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
vector<int> vec[1005],query;
int mark[1005];
int n,lv,k,tmp,que,cnt;

struct node{
    int id;
    int depth;
}x,tag,y;

//此题不可用dfs求解，原因：以示例为例，当输入查询6时，深搜可能先把第三轮才转发的人标记为已访问，那么return回到上一轮时，部分本应查找的人由于已被标记，跳过不再dfs，由此引起错误
void dfs(int node,int depth){
    if (depth > lv) {
        return ;
    }
    int len = vec[node].size();
    for (int i = 0; i<len; i++) {
        if (mark[vec[node][i]] == 0) {
            mark[vec[node][i]] = 1;
            cnt++;
            dfs(vec[node][i], depth+1);
        }
    }
}

void bfs(){
    queue<node> q;
    x.id = que;
    x.depth = 1;
    q.push(x);
    while (!q.empty()) {
        tag = q.front();
        q.pop();
        int len = vec[tag.id].size();
        for (int i = 0; i<len; i++) {
            if (mark[vec[tag.id][i]] == 0) {
                y.id = vec[tag.id][i];
                y.depth = tag.depth+1;
                cnt++;
                mark[vec[tag.id][i]] = 1;
                if (y.depth <= lv) {
                    q.push(y);
                }
            }
        }
    }
    
}

int main(){
    cin >> n >> lv;
    for (int i = 1; i<=n; i++) {
        cin >> k;
        for (int j = 0; j<k; j++) {
            cin >> tmp;
            vec[tmp].push_back(i);
        }
    }
    cin >> k;
    for (int i =0 ; i<k; i++) {
        cin >> que;
        cnt = 0;
        fill(mark, mark+1005, 0);
        mark[que] = 1;
//        dfs(que,1);
        bfs();
        cout << cnt << endl;
    }
    return 0;
}
