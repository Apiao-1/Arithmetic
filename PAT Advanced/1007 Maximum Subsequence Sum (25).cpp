//1007 Maximum Subsequence Sum (25) https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
//最大子段和永远是看前一位(dp[i-1],不是a[i-1])是否大于0，不是后一位
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int n,a[10001],tmp,lindex,rindex,max,tmpindex;
    while (cin >> n) {
        lindex = tmp = tmpindex = 0;
        max = -1;//注意此处max应为-1；
        rindex = n-1;
        for (int i = 0; i<n; i++) {
            cin >> a[i];
            tmp += a[i];
            if (tmp < 0) {
                tmp = 0;
                tmpindex = i+1;
            }else if (tmp > max) {//注意此处一定要是else if结构
                max = tmp;
                rindex = i;
                lindex = tmpindex;
            }
        }
        if (max < 0) {
            cout << 0 << " " << a[0] << " " << a[n-1] << endl;
        }else
            cout << max << " " << a[lindex] <<" " << a[rindex] << endl;
    }
    return 0;
}

////1007 Maximum Subsequence Sum (25) https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
////最大子段和永远是看前一位(dp[i-1],不是a[i-1])是否大于0，不是后一位
//#include <iostream>
//#include <vector>
//#include <stack>
//using namespace std;
//
//int main(){
//    int n,a[10001],dp[10001],length[10001];
//    while (cin >> n) {
//        fill(dp, dp+10001, 0);
//        fill(length, length+10001, 0);
//        for (int i = 0; i<n; i++) {
//            cin >> a[i];
//        }
//        dp[0] = a[0];
//        int max = a[0],flag = 0,len = 0;
//        for (int i = 1; i<n; i++) {
//            if (dp[i-1] > 0) {
//                dp[i] = dp[i-1] + a[i];
//                len++;
//            }else{
//                dp[i] = a[i];
//                len = 0;
//            }
//            length[i] = len;
//
//            if (dp[i] > max) {
//                max = dp[i];
//                flag = i;
//            }
//        }
//        if (max < 0) {
//            cout << 0 << " " << a[0] << " " << a[n-1] << endl;
//        }else
//            cout << max << " " << a[flag - length[flag]] <<" " << a[flag] << endl;
//    }
//    return 0;
//}
