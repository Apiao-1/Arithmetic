// 1002 A+B for Polynomials (25) https://pintia.cn/problem-sets/994805342720868352/problems/994805526272000000
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;

int main(){
    int n1,n2,tmp,cnt;
    float a[1001],val;
    while (cin >> n1) {
        cnt = 0;
        memset(a, 0, sizeof(a));
        for (int i=0; i<n1; i++) {
            cin >> tmp >> val;
            a[tmp] += val;//注意在同一行中可能多项式的指数会相同
        }
        cin >> n2;
        for (int i=0; i<n2; i++) {
            cin >> tmp >> val;
            a[tmp] += val;
        }
        for (int i=1000; i>=0; i--) {
            if (a[i] != 0) {
                cnt++;
            }
        }
        printf("%d",cnt);
        for (int i=1000; i>=0; i--) {
            if (a[i] != 0.0) {
                printf(" %d %.1f",i,a[i]);
            }
        }
    }
    return 0;
}
