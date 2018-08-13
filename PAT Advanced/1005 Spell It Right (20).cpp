// 1005 Spell It Right (20) https://pintia.cn/problem-sets/994805342720868352/problems/994805519074574336
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;
string ans[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main(){
    string str;
    while (cin >> str) {
        int len = str.length();
        int sum = 0,i;
        for (i= 0; i<len; i++) {
            sum += str[i] - '0';
        }
        str = to_string(sum);
        len = str.length();
        for (i = 0; i<len-1; i++) {
            cout << ans[str[i] - '0'] << " ";
        }
        cout <<ans[str[i] - '0'] << endl;
    }
    return 0;
}
