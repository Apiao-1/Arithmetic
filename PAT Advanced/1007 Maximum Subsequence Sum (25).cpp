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
for (int i = 1; i<n; i++) {
    if (dp[i-1] > 0) {
        dp[i] = dp[i-1] + a[i];
        len++;
    }else{
        dp[i] = a[i];
        len = 0;
    }
    length[i] = len;
    
    if (dp[i] > max) {
        max = dp[i];
        flag = i;
    }
}
//        if (max < 0) {
//            cout << 0 << " " << a[0] << " " << a[n-1] << endl;
//        }else
//            cout << max << " " << a[flag - length[flag]] <<" " << a[flag] << endl;
//    }
//    return 0;
//}

for (int i = 1;i <= n;i ++) { //按照袭击时间顺序确定每一个dp[i]
    int tmax = 1; //最大值的初始值为1，即以其结尾的最长不增子序列长度至少为
    1
    for (int j = 1;j < i;j ++) { //遍历其前所有导弹高度
        if (list[j] >= list[i]) { //若j号导弹不比当前导弹低
            tmax = max(tmax,dp[j] + 1); //将当前导弹排列在以j号导弹结尾
            的最长不增子序列之后，计算其长度dp[j] + 1,若大于当前最大值，则更新最大值
        }
    }
    dp[i] = tmax; //将dp[i]保存为最大值
}
int ans = 1;
for (int i = 1;i <= n;i ++) {
    ans = max(ans,dp[i]);
} //找到以每一个元素结尾的最长不增子序列中的最大值,该最大值即为答案
printf("%d\n",ans); //输出
