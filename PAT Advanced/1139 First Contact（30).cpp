//1139 First Contact（30)

//原始的写法无法区分0和-0，导致一组测试案例错误，还有一组超时，得分24；AC解中男生和女生的ID不会相同（题目中没有明确说），少了许多处理工作
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
//int mark[20010][20010];
//vector<int> e[20010];
//
//struct node{
//    int a,b;
//}tmp;
//vector<node> res;
//
//bool cmp(node x,node y){
//    if(x.a != y.a)
//        return x.a < y.a;
//    else
//        return x.b < y.b;
//}
//
//int main(){
//    freopen("a.txt","r",stdin);
//    int n,m,a,b,k;
//    scanf("%d%d",&n,&m);
//    for (int i = 0; i < m; i++)
//    {
//        scanf("%d%d",&a,&b);
//        a+=10000;
//        b+=10000;
//        mark[a][b] = mark[b][a] = 1;
//        if (((a >=10000 && b >= 10000)||(a <10000 &&b < 10000) )){
//        e[a].push_back(b);
//        e[b].push_back(a);
//        }
//    }
//    scanf("%d",&k);
//    for (int i = 0; i < k; i++)
//    {
//        res.clear();
//        int cnt = 0;
//        scanf("%d%d",&a,&b);
//        a+=10000;
//        b+=10000;
//        int len = e[a].size();
//        int len1 = e[b].size();
//        for (int i = 0; i < len; i++)
//        {
//            for (int j = 0; j < len1; j++){
//                if(e[a][i] == b){
//                    continue;
//                }
//                if (mark[e[a][i]][e[b][j]] == 1)
//                {
//                    tmp.a = e[a][i]-10000;
//                    tmp.a = tmp.a < 0 ? -tmp.a : tmp.a;
//                    tmp.b = e[b][j]-10000;
//                    tmp.b = tmp.b < 0 ? -tmp.b : tmp.b;
//                    res.push_back(tmp);
//                    cnt++;
//                }
//            }
//        }
//        cout << cnt << endl;
//        sort(res.begin(),res.end(),cmp);
//        if (cnt > 0)
//        {
//            vector<node> ::iterator i;
//            for (i = res.begin(); i!= res.end(); i++)
//            {
//                tmp = *i;
//                printf("%04d %04d\n",tmp.a,tmp.b);
//            }
//        }
//    }
//}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> arr;//新PAT系统中原代码导致了一个测试点内存超限，使用unordered_map<int, bool> arr 替代二维数组可避免内存超限
struct node {
    int a, b;
};
bool cmp(node x, node y) {
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}
int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<int> v[10000];
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (a.length() == b.length()) {//很巧妙，用长度判断是否为同性的朋友。解决了对0和-0的判断
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;
        vector<node> ans;
        for (int j = 0; j < v[abs(c)].size(); j++) {
            for (int k = 0; k < v[abs(d)].size(); k++) {
                if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;
                if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]] == true)
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", int(ans.size()));
        for(int j = 0; j < ans.size(); j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b);//输出千万要记得，否则位数不足的会输出错误，一开始检查了好久这个bug
    }
    return 0;
}
