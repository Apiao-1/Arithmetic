//1141 PAT Ranking of Institutions（25)
//已注意到要最后才对score进行保留处理，但还是有两个测试点过不去，得分21，找不到原因
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
//map<string,int> map1;
//int ind = 1;
//
//struct node{
//    string name;
//    int num;
//    double score;
//    double t,a,b;
//    int rank;
//}ans[100010];
//
//bool cmp(node a,node b){
//    if (a.score != b.score)return a.score > b.score;
//    else if(a.num!=b.num)
//        return a.num<b.num;
//    else return a.name < b.name;
//}
//
//int main(){
//    freopen("a.txt","r",stdin);
//    int n,id;
//    double s;
//    char c;
//    string str,tmp;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//
//        cin >> tmp >> s>>str;
//        int len = str.length();
//        for (int i = 0; i < len; i++)
//        {
//            str[i] = tolower(str[i]);
//        }
//        if (map1[str]==0)
//        {
//            id = ind;
//            map1[str] = ind++;
//        }else
//            id = map1[str];
//        if (tmp[0]=='T') ans[id].t += s;
//        else if (tmp[0]=='A') ans[id].a += s;
//        else if (tmp[0]=='B') ans[id].b += s;
//        ans[id].num++;
//        ans[id].name = str;
//    }
//    for (int i = 1; i < ind; i++)
//    {
//        ans[i].score =int(ans[i].t*1.5+ ans[i].a + ans[i].b/1.5);
//    }
//    sort(ans+1,ans+ind+1,cmp);
//    int rank = 1;
//    cout << ind-1<<endl;
//    cout << rank << " " << ans[1].name << " " << ans[1].score << " " << ans[1].num<<endl;
//    ans[1].rank = 1;
//    for (int i = 2; i < ind; i++)
//    {
//        rank++;
//        if (ans[i].score == ans[i-1].score)ans[i].rank = ans[i-1].rank;
//        else
//            ans[i].rank = rank;
//        cout << ans[i].rank << " " << ans[i].name << " " << ans[i].score << " " << ans[i].num<<endl;
//    }
//    return 0;
//}

#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <unordered_map>
using namespace std;
struct node {
    string school;
    int tws, ns;
};
bool cmp(node a, node b) {
    if (a.tws != b.tws)
        return a.tws > b.tws;
    else if (a.ns != b.ns)
        return a.ns < b.ns;
    else
        return a.school < b.school;
}
int main() {
    int n;
    scanf("%d", &n);
    unordered_map<string, int> cnt;
    unordered_map<string, double> sum;
    for (int i = 0; i < n; i++) {
        string id, school;
        cin >> id;
        double score;
        scanf("%lf", &score);
        cin >> school;
        for (int j = 0; j < school.length(); j++)
            school[j] = tolower(school[j]);
        if (id[0] == 'B')
            score = score / 1.5;
        else if (id[0] == 'T')
            score = score * 1.5;
        sum[school] += score;
        cnt[school]++;
    }
    vector<node> ans;
    for (auto it = cnt.begin(); it != cnt.end(); it++)
        ans.push_back(node{it->first, (int)sum[it->first], cnt[it->first]});
    sort(ans.begin(), ans.end(), cmp);
    int rank = 0, pres = -1;
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (pres != ans[i].tws) rank = i + 1;
        pres = ans[i].tws;
        printf("%d ", rank);
        cout << ans[i].school;
        printf(" %d %d\n", ans[i].tws, ans[i].ns);
    }
    return 0;
}
