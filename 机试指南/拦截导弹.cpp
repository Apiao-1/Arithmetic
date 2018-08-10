//https://www.nowcoder.com/practice/dad3aa23d74b4aaea0749042bba2358a?tpId=40&tqId=21408&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<cstring>
#include<algorithm>
#include <math.h>
using namespace std;
int a[30];

int main()
{
    int n,dp[30];
    while (cin >> n) {
        for (int i = 1; i<=n; i++) {
            cin >> a[i];
        }
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        for (int i = 2; i<=n; i++){//求每一个以i结尾的最长递减子序列dp[i]
            int amax =1;//求解每一个dp前都将max置为1
            for(int j = 1;j<i;j++){
                if (a[i] <= a[j]) {
                    amax = max(dp[j]+1,amax);
                }
            }
            dp[i] = amax;
        }
        int ans = dp[1];
        for (int i = 1; i<=n; i++) {
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }
        cout << ans <<endl;
        
    }
    return 0;
}
