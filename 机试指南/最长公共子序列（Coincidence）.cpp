//https://www.nowcoder.com/practice/f38fc44b43cf44eaa1de407430b85e69?tpId=40&tqId=21445&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<cstring>
#include<algorithm>
#include <math.h>
using namespace std;
int a[30];

int main()
{
    int dp[111][111];
    int lenx,leny;
    string x,y;
    while (cin >> x >> y) {
        lenx = (int)x.length();
        leny = (int)y.length();
        for (int i = 0; i<=lenx ; i++) {//初始化，已包括（i=0或j=0时，最长公共子序列为0）
            for (int j = 0; j<=leny ; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i<=lenx; i++) {
            for (int j = 1; j <=leny; j++) {
                if (x[i-1] == y[j-1]) {//注意string是从0开始放置的，但dp数组是从1开始放的
                    dp[i][j] = dp[i-1][j-1] +1;//注意i,j需从1开始，否则数组会越界
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[lenx][leny] << endl;
        
        
    }
    return 0;
}
