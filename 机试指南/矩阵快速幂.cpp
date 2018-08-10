//矩阵快速幂https://www.nowcoder.com/practice/31e539ab08f949a8bece2a7503e9319a?tpId=40&tqId=21523&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
int n,ans[11][11];

void compute(int a[][11],int b[][11]){
    int i=0,j=0;
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            int sum = 0;
            for (int k =0; k<n; k++) {
                sum += a[i][k] * b[k][j];
            }
            ans[i][j] = sum;
        }
    }
    for (i=0; i<n; i++) {
        for (j=0; j<n; j++) {
            a[i][j] = ans[i][j];
        }
    }
}

int main()
{
    int i=0,j=0,k;
    int a[11][11],b[11][11];
    while(cin >> n >> k){
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                cin >> a[i][j];
                b[i][j] = 0;
                if (i == j) {
                    b[i][j] = 1;
                }
            }
        }
        while(k){
            if(k%2 == 1){
                compute(b,a);
            }
            k /= 2;
            compute(a,a);
        }
        for (i=0; i<n; i++) {
            for (j=0; j<n-1; j++) {
                cout << b[i][j] << " ";
            }
            cout << b[i][j] << endl;
        }
        
        
    }
    return 0;
}
