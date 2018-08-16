//1077 Kuchiguse (20) https://pintia.cn/problem-sets/994805342720868352/problems/994805390896644096
//最长后缀子串，需要注意的是getline的使用（gets方法目前已废除）；输入时若将字符串先直接反转，则可以免去len[k]的记录长度的数组
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

int main() {
    int n,k,len[101];
    string str[101];
    string ans ="";
    scanf("%d\n",&n);
    for (k = 0; k<n; k++) {
        getline(cin,str[k]);//用处与gets相同，gets函数目前已被废除
        len[k] = str[k].length();
    }
    for (int i = 1; i <= len[0]; i++) {
        int cnt = 0;
        for (int j = 1; j<n; j++) {
            if (len[j]-i >=0) {
                if (str[0][len[0]-i] == str[j][len[j]-i]) {
                    cnt++;
                }
            }
        }
        if (cnt == n-1) {
            ans += str[0][len[0]-i];
        }else
            break;
    }
    reverse(ans.begin(), ans.end());
    if (ans.length() == 0) {
        cout <<"nai" << endl;
    }
    else
        cout << ans << endl;
    return 0;
}
