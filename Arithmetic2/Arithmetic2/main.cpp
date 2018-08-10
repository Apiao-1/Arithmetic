//矩阵快速幂https://www.nowcoder.com/practice/31e539ab08f949a8bece2a7503e9319a?tpId=40&tqId=21523&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
int buff[101],n;

int LIS(){
    int dp[n+1],max = -9999;
    dp[0] = buff[0];
    for (int i = 1; i<n; i++) {
        if(dp[i-1] > 0)
            dp[i] = dp[i-1] + buff[i];
        else
            dp[i] = buff[i];
        if (dp[i] > max) {
            max = dp[i];
        }
    }
    return max;
}

int main()
{
    int a[101][101],tmp;
    while (cin >> n) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin >> a[i][j];
            }
        }
        int max = -9999;
        for (int i = 0; i<n; i++) {//遍历n行
            memset(buff, 0, sizeof(buff));
            for (int j=i; j<n; j++) {//表示以i行为起始行，第j行为终止行
                for (int k = 0; k<n; k++) {//表示第k列，通过累加转变为一维数组求最大值
                    buff[k] += a[j][k];
//                    printf("从%d行到%d行的buff[%d]是：%d \n",i,j,k,buff[k]);
                }
                tmp = LIS();//最大子段和
//                printf("tmp=%d  \n",tmp);
                
                if (tmp > max ) {
                    max = tmp;

                }

            }
        }
        cout << max << endl;
        
        
    }
    return 0;
}
