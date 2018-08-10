//https://www.nowcoder.com/profile/2575579/codeBookDetail?submissionId=28486411
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int status[10001];//0表示为素数，1表示不是素数
int ans[10001],length;


void getNum(){
    status[0] = status[1] = length = 0;
    for (int i=2; i<10001; i++) {
        if (!status[i]) {
            ans[length++] = i;
            int  k = i;
            for (int j = k*i;j < 10001;j = k*i) {
                status[j] = 1;
                k++;
            }
        }
    }
}

int main() {
    int n,j;
    bool has_ans;
    getNum();
    while(cin >> n){
        has_ans = 0;
        for (j = 0; ans[j] < n;j++) {
            
            if (ans[j] % 10 == 1) {
                if (!has_ans) {
                    cout << ans[j];
                    has_ans = 1;
                }else
                    cout << " " << ans[j];
            }
        }
        if (!has_ans) {
            cout << -1;
        }
        
    }
    return 0;
}
