//1040 Longest Symmetric String（25）
//DP，求回文串，将原序列逆序后，即求解两个序列的最长公共子串
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;
int dp[1010][1010];


int main(){
    string str,rev;
    int max= 0;
    getline(cin, str);
    rev = str;
    int len = str.length();
    reverse(str.begin(), str.end());
//    cout << str << endl;
    for (int i = 0; i<=len; i++) {
        for (int j = 0; j<=len; j++) {
            if (i == 0|| j == 0) {//注意这里的初始化过程
                dp[i][j] = 0;
            }else if (str[i-1] == rev[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
                if (dp[i][j] > max) {
                    max = dp[i][j];
                }
            }else
                dp[i][j] = 0;
        }
    }
    cout << max << endl;
    return 0;
}
