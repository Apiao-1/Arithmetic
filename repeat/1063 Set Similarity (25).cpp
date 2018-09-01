//1063 Set Similarity (25)https://pintia.cn/problem-sets/994805342720868352/problems/994805409175420928
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
int n,m,k;
vector<set<int>> vec(55);//vec[55]下方就会报错，暂时不清楚和（）的区别

//map方法在数据量大时会超时
//void query(int q1,int q2){
//    hashmap.clear();
//    set<int> ::iterator i = a[q1].begin();
//    for (; i != a[q1].end(); i++) {
//        hashmap[*i]++;
//    }
//    set<int> ::iterator j = a[q2].begin();
//    for (; j != a[q2].end(); j++) {
//        hashmap[*j]++;
//    }
//    map<int, int> :: iterator itor = hashmap.begin();
//    int num = 0;
//    for (; itor != hashmap.end(); itor++) {
////        cout << itor->first << " " << itor->second << endl;
//        if (itor->second > 1) {
//            num++;
//        }
//    }
//    printf("%.1f%%\n",100.0*num/hashmap.size());
//}

void query1(int q1,int q2){
    int x = 0,y = vec[q2].size();
    for (auto itor = vec[q1].begin(); itor != vec[q1].end(); itor++) {
        if (vec[q2].count(*itor) > 0) {
            x++;
        }else
            y++;
    }
    printf("%.1f%%\n",100.0*x/y);
}


int main(){
    int tmp;
    scanf("%d",&n);
    for (int i = 1; i<=n; i++) {
        scanf("%d" ,&m);
        set<int> a;
        for (int j = 0; j<m; j++) {
            scanf("%d",&tmp);
            a.insert(tmp);
        }
        vec[i] = a;
    }
    scanf("%d",&k);
    int q1,q2;
    for (int i = 0; i<k; i++) {
        scanf("%d%d" ,&q1,&q2);
//        query(q1,q2);
        query1(q1,q2);
    }
    return 0;
}
