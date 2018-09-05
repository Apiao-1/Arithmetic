//1137 Final Grading（25)
//更好的写法
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <string.h>
//#include <algorithm>
//#include <math.h>
//#include <vector>
//#include <map>
//using namespace std;
//
//struct node{
//    string name;
//    int gp=-1,gm=-1,gf=-1,g;
//    //    int gp,gm,gf,g;
//}s[100010];
//vector<node> ans;
//
//bool cmp(node a,node b){
//    if (a.g != b.g)
//    {
//        return a.g > b.g;
//    }else
//    {
//        return a.name < b.name;
//    }
//}
//
//
//int main(){
//    int p,m,n,index = 0,id;
//    double sum = 0;
//    string str;
//    cin >> p>>m>>n;
//    map<string,int> map1;
//    for (int i = 0; i < p; i++)
//    {
//        cin >> str;
//        if(map1.count(str)==0){
//            id = index;
//            map1[str] = index++;
//        }else
//        {
//            id = map1[str];
//        }
//        cin >> s[id].gp;
//        s[id].name = str;
//    }
//    for (int i = 0; i < m; i++)
//    {
//        cin >> str;
//        if(map1.count(str)==0){
//            id = index;
//            map1[str] = index++;
//        }else
//        {
//            id = map1[str];
//        }
//        cin >> s[id].gm;
//        s[id].name = str;
//    }
//    for (int i = 0; i < n; i++)
//    {
//        cin >> str;
//        if(map1.count(str)==0){
//            id = index;
//            map1[str] = index++;
//        }else
//        {
//            id = map1[str];
//        }
//        cin >> s[id].gf;
//        s[id].name = str;
//    }
//    for (int i = 0; i < index; i++)
//    {
//        sum = 0;
//        if (s[i].gp >= 200)
//        {
//            if (s[i].gf >= s[i].gm)
//            {
//                s[i].g = s[i].gf;
//            }else
//            {
//                sum = 1.0*s[i].gm*0.4+1.0*s[i].gf*0.6;
//                s[i].g = sum+0.5;
//            }
//            if (s[i].g >= 60)
//            {
//                ans.push_back(s[i]);
//            }
//        }
//    }
//    sort(ans.begin(),ans.end(),cmp);
//    int len = ans.size();
//    for (int i = 0; i < len; i++)
//    {
//        cout << ans[i].name <<" " << ans[i].gp <<" " << ans[i].gm<<" " << ans[i].gf <<" " << ans[i].g << endl;
//    }
//    return 0;
//}

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct node {
    string name;
    int gp, gm, gf, g;
};
bool cmp(node a, node b) {
    return a.g != b.g ? a.g > b.g : a.name < b.name;
}
map<string, int> idx;
int main() {
    int p, m, n, score, cnt = 1;
    cin >> p >> m >> n;
    vector<node> v, ans;
    string s;
    for (int i = 0; i < p; i++) {
        cin >> s >> score;
        if (score >= 200) {
            v.push_back(node{s, score, -1, -1, 0});
            idx[s] = cnt++;
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> s >> score;
        if (idx[s] != 0) v[idx[s] - 1].gm = score;
    }
    for (int i = 0; i < n; i++) {
        cin >> s >> score;
        if (idx[s] != 0) {
            int temp = idx[s] - 1;
            v[temp].gf = v[temp].g = score;
            if (v[temp].gm > v[temp].gf) v[temp].g = int(v[temp].gm * 0.4 + v[temp].gf * 0.6 + 0.5);
        }
    }
    for (int i = 0; i < v.size(); i++)
        if (v[i].g >= 60) ans.push_back(v[i]);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
        printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
    return 0;
}
