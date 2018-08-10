//https://www.nowcoder.com/practice/376537f4609a49d296901db5139639ec?tpId=40&tqId=21339&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <climits>
using namespace std;

int main(){
    int n,ans[1000001];
    while (cin >> n) {
        ans[0] = 1;
        for (int i = 1; i<=n; i++) {
            if (i % 2 != 0) {
                ans[i] = ans[i-1];
            }else
                ans[i] = (ans[i-1] + ans[i/2])%1000000000 ;
        }
        cout << ans[n];
    }
    return 0;
}
