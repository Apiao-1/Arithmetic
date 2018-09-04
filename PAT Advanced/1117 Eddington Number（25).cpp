//1117 Eddington Number（25)
//一组案例过不了，21分
//#include <iostream>
//#include <string>
//#include <math.h>
//#include <cstring>
//#include <algorithm>
//#include <vector>
//#include <map>
//#include <queue>
//#include <set>
//#include <cstdio>
//using namespace std;
//int a[1000010];
//
//int main(){
//    int n,tmp,max =0 ;
//    cin >> n;
//    for (int i = 0; i<n; i++) {
//        scanf("%d",&tmp);
//        a[tmp]++;
//    }
//    for (int i = 0; i<n && n > 0; i++) {
//        int tag = a[i];
//        a[i] = n - a[i];
//        n -= tag;
//        if (a[i] > i) {
//            if (i > max) {
//                max = i;
//            }
//
//        }
//    }
//    cout << max << endl;
//    return 0;
//}


#include<cstdio>
#include<algorithm>
#define N 100001
using namespace std;
int j,n,ans,a[N];
int main(){
    scanf("%d",&n);
    for(int i=0 ;i<n ;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for(j=n-1,ans=1 ;j>=0 ;j--,ans++){
        if(a[j]<=ans)break;//a[j] > ans 时表示有ans天的骑行距离都要大于ans,符合题意，故继续循环
    }
    //因为当判断到<=才退出循环，因此答案是前一天
    printf("%d\n",ans-1);
    
    return 0;
}
