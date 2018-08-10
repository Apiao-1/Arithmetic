//https://www.nowcoder.com/profile/2575579/codeBookDetail?submissionId=28790541
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main(){
    int n,a[101],dp1[101],dp2[101];
    while (cin >> n) {
        for (int i = 0; i<n; i++) {
            cin >> a[i];
        }
        memset(dp2, 0, sizeof(dp2));
        for (int i = 0; i < n; i++) {//求最长递增子序列
            dp1[i] = 1;
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j]) {
                    dp1[i] = max(dp1[j] + 1, dp1[i]);
                }
            }
        }
        
        for (int i = n-1; i >=0; i--) {//求逆序的最长递增子序列
            dp2[i] = 1;
            for (int j = n-1; j >i; j--) {
                if (a[i] > a[j]) {
                    dp2[i] = max(dp2[j] + 1, dp2[i]);
                }
            }
        }
        
        int max = 0,flag = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i]+dp2[i] > max) {
                max =dp1[i]+dp2[i] ;
                flag = i;
            }
        }
        cout << n - max + 1 << endl;
        
    }
    
    
    return 0;
}
