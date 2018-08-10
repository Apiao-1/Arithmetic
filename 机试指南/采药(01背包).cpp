//https://www.nowcoder.com/practice/376537f4609a49d296901db5139639ec?tpId=40&tqId=21339&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <climits>
using namespace std;

int main(){
    int t,m,w[101],v[101],dp[1001];//dp[i][j]表示前i件物品在最大耗时为j时的最大价值
    while (cin >> t>> m) {
        for (int i = 1; i<=m; i++) {
            cin >> w[i] >> v[i];
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i<=m;i++){//遍历每一种物品
            for(int j = t; j >= 0;j--){
                if (w[i] <= j) {
                    dp[j] = max(v[i] + dp[j-w[i]], dp[j]);
                }
            }
        }
        cout << dp[t] << endl;
    }
    return 0;
}
