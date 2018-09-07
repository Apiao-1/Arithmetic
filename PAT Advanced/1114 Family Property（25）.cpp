//1114 Family Property（25）
//并查集的考察，一开始没做出，变化的是每次union操作以最小的元素为根节点进行合并
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
int id[1005],root[10010],mark[10010],sets[10010],area[10010];

struct node{
    int id,people;
    double sets,area;
}p[10010];
vector<node>ans;

int findroot(int x){
    int tmp = x;
    while(root[x] != x)
        x = root[x];
    while (root[tmp] != x) {
        int a = root[tmp];
        root[tmp] = x;
        tmp = a;
    }
    return x;
}

void Union(int a,int b){
    a = findroot(a);
    b = findroot(b);
    a < b ? root[b] = a : root[a] = b;
}

bool cmp(node a, node b){
    if (a.area != b.area) {
        return a.area > b.area;
    }else
        return a.id < b.id;
    
}

int main(){
    int n,fid,mid,k,kid,tmp,cnt=0;
    cin >> n;
    for (int i = 0; i<10010; i++) {
        root[i] = i;
        p[i].id = i;
    }
    for (int i = 0; i<n; i++) {
        cin >> id[i] >> fid >> mid;
        if (fid != -1) Union(id[i],fid);
        if (mid != -1) Union(id[i],mid);
        cin >> k;
        for (int j=0; j<k; j++) {
            cin >> kid;
            Union(kid, id[i]);
        }
        cin >> sets[id[i]] >> area[id[i]];
    }
    for (int i = 0; i<n; i++) {
        tmp = findroot(id[i]);
        if (mark[tmp] == 0) {
            mark[tmp] = 1;
            cnt++;
        }
        p[tmp].sets += sets[id[i]];
        p[tmp].area += area[id[i]];
    }
    for (int i = 0; i<10010; i++) {
        root[i] = findroot(i);//要注意每一个节点最后都要再做一遍findroot，否则会有部分节点的根节点不是最终的根节点
        if (root[i] != i) {
            p[root[i]].people++;
        }
    }
    for (int i = 0; i<10010; i++) {
        if (mark[i]) {
            p[i].people++;
            p[i].area /= p[i].people;
            p[i].sets /= p[i].people;
            ans.push_back(p[i]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    cout << cnt << endl;
    int len = ans.size();
    for (int i = 0; i<len; i++) {
        printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].people,ans[i].sets,ans[i].area);
    }
    return 0;
}
