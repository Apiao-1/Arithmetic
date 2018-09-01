//1120 Friend Numbers（20）
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
using namespace std;
int ans[100];

int main(){
    int n,sum,cnt = 0;
    string str;
    cin >> n;
    for (int i =0; i<n; i++) {
        cin >> str;
        sum = 0;
        int len = str.length();
        for (int j = 0; j<len; j++) {
            sum += str[j] - '0';
        }
        if (ans[sum] == 0) {
            cnt++;
            ans[sum]++;
        }
    }
    cout << cnt << endl;
    int flag = 1;
    for (int i = 0; i<100; i++) {
        if (ans[i] > 0 && flag) {
            cout << i ;
            flag = 0;
        }else if(ans[i] > 0 ){
            cout << " " << i ;
        }
    }
    cout << endl;
    return 0;
}

