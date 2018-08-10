//http://acm.hdu.edu.cn/showproblem.php?pid=1421
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <climits>
using namespace std;

int main(){
    int n,k,w[2001],dp[2001][1001];//dp[i][j]表示从i件物品之间选择j对所耗费的体力
    while (cin >> n >> k) {
        for (int i = 1; i<=n; i++) {
            cin >> w[i];
        }
        sort(w+1, w+n+1);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=INT_MAX;//初始化小了不行 9999999也不行
                dp[i][0]=0;
                
            }

        for (int i = 2; i<=n; i++) {
            for (int j = 1; j*2<=i && j <=k; j++) {
                dp[i][j] = min((w[i]-w[i-1])*(w[i]-w[i-1])+dp[i-2][j-1],dp[i-1][j]);
            }
        }
        cout << dp[n][k] << endl;
        
    }
    
    return 0;
}
