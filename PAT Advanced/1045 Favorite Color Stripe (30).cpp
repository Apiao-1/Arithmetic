////1045 Favorite Color Stripe (30) https://pintia.cn/problem-sets/994805342720868352/problems/994805437411475456
//考察最长公共子序列的变种（LCS），允许元素重复
/*/
 这道题目，按照正常的思路求解，应该使用最长公共子序列算法LCS，但与常规的LCS有所差别，常规LCS是从两个序列中按索引递增顺序，不重复的选取最大公共子列，而现在的问题是在序列B中按照A中的元素顺序可重复的找出最大子列，这样说起来比较抽象，下面举个例子，对于序列：
 
 A=｛2,3,1,5,6｝ B={2,2,4,1,5,5,6,3,1,1,5,6}
 
 如果是常规的LCS，我们找到的子列将会是{2,3,1,5,6}，因为B完全的包含了A（不必连续）
 
 如果是可重复的LCS，我们完全可以选择{2,2,3,1,1,5,6}，这便是变种的LCS。
 
 对于常规的LCS，只有A[i] = B[j]时才让当前的最大子列长度为maxLen[i-1][j-1]+1，其他情况则取maxLen[i-1][j]或者maxLen[i][j-1]中的最大值，这样的算法只能不重复的找出子列，如果要考虑重复，应该修改算法，无论什么情况，都取maxLen[i-1][j-1]、maxLen[i-1][j]和maxLen[i][j-1]中的最大值，如果A[i]=B[j]，则在最大值的基础上+1，这样就可以处理重复的情况了。
 /*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;
int dp[210][10010];

int main() {
    int n,m,k;
    cin >> k;
    cin >> n;
    int a[210];
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
    cin >> m;
    int b[10010];
    for (int i = 1; i<=m; i++) {
        cin >> b[i];
    }
    int max = 0;
    fill(dp[0], dp[0] + 210*10010, 0);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            max = dp[i-1][j-1];
            if (max < dp[i-1][j]) max = dp[i-1][j];
            if (max < dp[i][j-1]) max = dp[i][j-1];
            if (a[i] == b[j]) {
                dp[i][j] = max + 1;
            }else
                dp[i][j] = max;
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
