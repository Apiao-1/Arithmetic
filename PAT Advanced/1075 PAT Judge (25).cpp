//1075 PAT Judge (25) https://pintia.cn/problem-sets/994805342720868352/problems/994805393241260032
//最后一组测试样例一直无法通过，不解
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

struct student{
    char id[6];
    int cnt = 0,sum = 0;
    int score[10],flag[10];
}s[10010];

bool cmp(struct student a,struct student b){
    if (a.sum != b.sum) {
        return a.sum > b.sum;
    }else if(a.cnt != b.cnt)
        return a.cnt > b.cnt;
    else
        return strcmp(a.id, b.id) < 0;
        
}

int main() {
    int n,k,m,full[10],tmp,sco,num;
    char inId[6];
    scanf("%d%d%d",&n,&k,&m);
    for (int i = 1; i<=k; i++) {
        scanf("%d",&full[i]);
    }
    for (int i = 1; i<=m; i++) {
        scanf("%s%d%d",inId,&tmp,&sco);
        num = 0;
        for (int j=0;j<5; j++) {
            if (inId[j] != '0') {
                num = 10*num + inId[j] - '0';
            }
        }
        strcpy(s[num].id,inId);
        s[num].flag[tmp] = 1;//表示该题已有提交
        if (sco != -1) {
            s[num].flag[0] = 1;//只要有能通过编译器的提交，该成绩就需要输出
        }
        if (sco == full[tmp]) {
            s[num].cnt++;
        }
        if (sco > s[num].score[tmp]) {
            s[num].sum += sco - s[num].score[tmp];
            s[num].score[tmp] = sco;
        }
    }
    for (int i = 0; i<n; i++) {
        if (s[i].flag[0] != 1) {
            s[i].sum = -9999;
        }
    }
    sort(s+1, s+n+1, cmp);
    int order = 0,mid = 0;
    for (int i=1; i<=n; i++) {
        if(s[i].flag[0] == 1){
            if(s[i].sum != s[i-1].sum){
                order++;
                order+= mid;
                mid = 0;
            }else
                mid++;
            printf("%d %s %d",order,s[i].id,s[i].sum);
            for (int j = 1; j<=k; j++) {
                if (s[i].flag[j] == 1) {
                    printf(" %d",s[i].score[j]);
                }else
                    printf(" -");
            }
            printf("\n");
        }
    }
    return 0;
}
//AC代码
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//struct node {
//    int rank, id, total = 0;
//    vector<int> score;
//    int passnum = 0;
//    bool isshown = false;
//};
//bool cmp1(node a, node b) {
//    if(a.total != b.total)
//        return a.total > b.total;
//    else if(a.passnum != b.passnum)
//        return a.passnum > b.passnum;
//    else
//        return a.id < b.id;
//}
//
//int main() {
//    int n, k, m, id, num, score;
//    scanf("%d %d %d", &n, &k, &m);
//    vector<node> v(n + 1);
//    for(int i = 1; i <= n; i++)
//        v[i].score.resize(k + 1, -1);
//    vector<int> full(k + 1);
//    for(int i = 1; i <= k; i++)
//        scanf("%d", &full[i]);
//    for(int i = 0; i < m; i++) {
//        scanf("%d %d %d", &id, &num, &score);
//        v[id].id = id;
//        v[id].score[num] = max(v[id].score[num], score);
//        if(score != -1)
//            v[id].isshown = true;
//        else if(v[id].score[num] == -1)
//            v[id].score[num] = -2;
//    }
//    for(int i = 1; i <= n; i++) {
//        for(int j = 1; j <= k; j++) {
//            if(v[i].score[j] != -1 && v[i].score[j] != -2)
//                v[i].total += v[i].score[j];
//            if(v[i].score[j] == full[j])
//                v[i].passnum++;
//        }
//    }
//    sort(v.begin() + 1, v.end(), cmp1);
//    for(int i = 1; i <= n; i++) {
//        v[i].rank = i;
//        if(i != 1 && v[i].total == v[i - 1].total)
//            v[i].rank = v[i - 1].rank;
//    }
//    for(int i = 1; i <= n; i++) {
//        if(v[i].isshown == true) {
//            printf("%d %05d %d", v[i].rank, v[i].id, v[i].total);
//            for(int j = 1; j <= k; j++) {
//                if(v[i].score[j] != -1 && v[i].score[j] != -2)
//                    printf(" %d", v[i].score[j]);
//                else if(v[i].score[j] == -1)
//                    printf(" -");
//                else
//                    printf(" 0");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}
