//1019 Prime Factors (25)https://www.nowcoder.com/pat/5/problem/4112
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <cstring>
using namespace std;

int main(){
    long n;
    int cnt;
    while (cin >> n) {
        if (n==1) {
            cout << "1=1"<<endl;
            continue;
        }
        cout << n << "=";
        long tmp = n;
        int flag = 1;
        for (int i=2; i<sqrt(n)+1; i++) {
            cnt = 0;
            while (tmp % i ==0) {
                tmp /= i;
                cnt++;
            }
            if(!flag){
                if (cnt == 1)
                    cout << "*" << i;
                else if(cnt > 1)
                    cout << "*" << i << "^" << cnt;
            }else if(flag){
                if (cnt == 1){
                    cout << i;
                    flag = 0;
                }
                else if(cnt > 1){
                    cout << i << "^" << cnt;
                    flag = 0;
                }
            }
        }
        if (tmp>1) {
            if (flag) {
                cout << tmp;
            }else
                cout << "*" << tmp;
        }
        cout << endl;
    }
    return 0;
}
