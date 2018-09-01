//1034 Head of a Gang (30) https://pintia.cn/problem-sets/994805342720868352/problems/994805456881434624
//方法一 使用并查集相关内容
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
using namespace std;
int root[2001];

struct ans{
    string name;
    int num;
}x;

int findroot(int a){
    int tempt = a,x;
    while (root[a] != -1) {
        a = root[a];
    }
    while (root[tempt] != -1) {
        x = root[tempt];
        root[tempt] = a;
        tempt = x;
    }
    return a;
}

bool cmp(struct ans a,struct ans b){
    return a.name < b.name;
}

int main() {
    int n,stand,time,flag,tmp,sum[2001],index = 0,a,b;
    char str1[5],str2[5];
    vector<ans> res;
    map<string, int> map1;
    map<int, string> map2;
    fill(sum, sum+2001, 0);
    fill(root, root+2001, -1);//初始时所有点都是孤立的
    scanf("%d%d",&n,&stand);
    for (int i = 0; i<n; i++) {
        flag = 0;
        scanf("%s %s %d",str1,str2,&time);
        if(map1.count(str1) == 0){
            map2[index] = str1;
            map1[str1] = index++;
        }if (map1.count(str2) == 0) {
            map2[index] = str2;
            map1[str2] = index++;
        }
        sum[map1[str1]] += time;
        sum[map1[str2]] += time;
        a = findroot(map1[str1]);
        b = findroot(map1[str2]);
        if (a != b) {
            root[b] = a;
        }
    }
    vector<int> vec[2001];
    int len = map1.size(),num = 0;
//    for (auto i = map1.begin(); i != map1.end(); i++) {
//        cout << i->first << " " << i->second << endl;
//    }
//    for (auto i = map2.begin(); i != map2.end(); i++) {
//        cout << i->first << " " << i->second << endl;
//    }
    for (int i = 0; i<len ; i++) {
        int a = findroot(i);
        vec[a].push_back(i);
    }
    res.clear();
    for (int i = 0; i<len; i++) {
        if (vec[i].size() > 2) {
            tmp = time = sum[vec[i][0]];
            flag = vec[i][0];
            for (int j = 1; j<vec[i].size(); j++) {
                time += sum[vec[i][j]];
                if (sum[vec[i][j]] > tmp) {
                    tmp = sum[vec[i][j]];
                    flag = vec[i][j];
                }
            }
            if (time > 2*stand) {
                num++;
                x.name = map2[flag];
                x.num = vec[findroot(flag)].size();
                res.push_back(x);
            }
        }
    }
    sort(res.begin(), res.end(), cmp);
    printf("%d\n" , num);
    for (int i = 0; i<res.size(); i++) {
        cout << res[i].name << " "<< res[i].num << endl;
    }
    return 0;
}
//方法二 dfs遍历图
//#include <iostream>
//#include <map>
//using namespace std;
//map<string, int> stringToInt;
//map<int, string> intToString;
//map<string, int> ans;
//int idNumber = 1, k;
//int stoifunc(string s) {
//    if(stringToInt[s] == 0) {
//        stringToInt[s] = idNumber;
//        intToString[idNumber] = s;
//        return idNumber++;
//    } else {
//        return stringToInt[s];
//    }
//}
//int G[2010][2010], weight[2010];
//bool vis[2010];
//void dfs(int u, int &head, int &numMember, int &totalweight) {
//    vis[u] = true;
//    numMember++;
//    if(weight[u] > weight[head])
//        head = u;
//    for(int v = 1; v < idNumber; v++) {
//        if(G[u][v] > 0) {
//            totalweight += G[u][v];
//            G[u][v] = G[v][u] = 0;
//            if(vis[v] == false)
//                dfs(v, head, numMember, totalweight);
//        }
//    }
//}
//void dfsTrave() {
//    for(int i = 1; i < idNumber; i++) {
//        if(vis[i] == false) {
//            int head = i, numMember = 0, totalweight = 0;
//            dfs(i, head, numMember, totalweight);
//            if(numMember > 2 && totalweight > k)
//                ans[intToString[head]] = numMember;
//        }
//    }
//}
//int main() {
//    int n, w;
//    cin >> n >> k;
//    string s1, s2;
//    for(int i = 0; i < n; i++) {
//        cin >> s1 >> s2 >> w;
//        int id1 = stoifunc(s1);
//        int id2 = stoifunc(s2);
//        weight[id1] += w;
//        weight[id2] += w;
//        G[id1][id2] += w;
//        G[id2][id1] += w;
//    }
//    dfsTrave();
//    cout << ans.size() << endl;
//    for(auto it = ans.begin(); it != ans.end(); it++)
//        cout << it->first << " " << it->second << endl;
//    return 0;
//}
