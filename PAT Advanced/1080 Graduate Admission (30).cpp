
//1080 Graduate Admission (30) https://pintia.cn/problem-sets/994805342720868352/problems/994805387268571136
//这个写法不会有bug但在PAT运行超时
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct stu{
    int ge,gi,index;
    int k[5];
}stu[41000];

bool cmp(struct stu a,struct stu b){
    if ((a.ge + a.gi) !=(b.ge + b.gi) ) {
        return (a.ge + a.gi) >(b.ge + b.gi) ;
    }else
        return a.ge > b.ge;
}

int main(){
    int n,m,k,j;
    scanf("%d",&n);
    scanf("%d%d",&m,&k);
    int limit[m];
    vector<int> ans[m];
    for (int i = 0; i<m; i++) {
        scanf("%d",&limit[i]);
        ans[i].clear();
    }
    for (int i = 0; i<n; i++) {
        scanf("%d%d",&stu[i].ge,&stu[i].gi);
        stu[i].index = i;
        for (int j =0; j<k; j++) {
            scanf("%d",&stu[i].k[j]);
        }
    }
    sort(stu, stu+n, cmp);
    //    for (int i = 0; i<n; i++) {
    //        cout << stu[i].ge << " " << stu[i].gi << " " << stu[i].k[0] <<stu[i].k[1] << stu[i].k[2] <<" "  << stu[i].index << endl;
    //    }
    int flag = 0,p;
    for (int i = 0; i<n; i++) {
        if (i > 0 && ((stu[i].ge + stu[i].gi) == (stu[i-1].ge + stu[i-1].gi)) && (stu[i].ge == stu[i-1].ge)) {
            flag++;//判断同名的人数
        }else
            flag = 0;
        for (int j = 0; j<k; j++) {
            p = stu[i].k[j];
            int len = ans[p].size();
            if (len < limit[p]) {
                ans[p].push_back(stu[i].index);
                break;
            }else if(flag > 0 && len>0 ){
                for (int q = flag; q>0 ; q--) {
                    if (ans[p].back() == stu[i-q].index) {
                        ans[p].push_back(stu[i].index);
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i<m; i++) {
        if (ans[i].size() == 0) {
            printf("\n");
            continue;
        }
        sort(ans[i].begin(), ans[i].end());
        for (j = 0; j<ans[i].size()-1; j++) {
            printf("%d ",ans[i][j]);
        }
        printf("%d\n",ans[i][j]);
    }
    return 0;
}
//该写法无法判断多人重分时，A去了学校1，B去了学校2，C想去学校1的情况，但可以通过PAT
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <stack>
//using namespace std;
//
//struct stu{
//    int ge,gi,index;
//    int k[5];
//}stu[41000];
//
//bool cmp(struct stu a,struct stu b){
//    if ((a.ge + a.gi) !=(b.ge + b.gi) ) {
//        return (a.ge + a.gi) >(b.ge + b.gi) ;
//    }else
//        return a.ge > b.ge;
//}
//
//int main(){
//    int n,m,k,j;
//    scanf("%d",&n);
//    scanf("%d%d",&m,&k);
//    int limit[m];
//    vector<int> ans[m];
//    for (int i = 0; i<m; i++) {
//        scanf("%d",&limit[i]);
//        ans[i].clear();
//    }
//    for (int i = 0; i<n; i++) {
//        scanf("%d%d",&stu[i].ge,&stu[i].gi);
//        stu[i].index = i;
//        for (int j =0; j<k; j++) {
//            scanf("%d",&stu[i].k[j]);
//        }
//    }
//    sort(stu, stu+n, cmp);
//    //        for (int i = 0; i<n; i++) {
//    //            cout << stu[i].ge << " " << stu[i].gi << " " << stu[i].k[0] <<stu[i].k[1] << stu[i].k[2] <<" "  << stu[i].index << endl;
//    //        }
//    int flag = 0,p;
//    for (int i = 0; i<n; i++) {
//        flag = 0;
//        if (i > 0 && ((stu[i].ge + stu[i].gi) == (stu[i-1].ge + stu[i-1].gi)) && (stu[i].ge == stu[i-1].ge)) {
//            flag = 1;//判断是否同名次
//        }
//        for (int j = 0; j<k; j++) {
//            p = stu[i].k[j];
//            if (ans[p].size() < limit[p]) {
//                ans[p].push_back(stu[i].index);
//                break;
//            }else if(flag){
//                if (ans[p].size()>0 && ans[p].back() == stu[i-1].index) {
//                    ans[p].push_back(stu[i].index);
//                    break;
//                }
//            }
//        }
//    }
//    for (int i = 0; i<m; i++) {
//        if (ans[i].size() == 0) {
//            printf("\n");
//            continue;
//        }
//        sort(ans[i].begin(), ans[i].end());
//        for (j = 0; j<ans[i].size()-1; j++) {
//            printf("%d ",ans[i][j]);
//        }
//        printf("%d\n",ans[i][j]);
//    }
//    return 0;
//}
//


