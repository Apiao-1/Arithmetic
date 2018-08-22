//1038 Recover the Smallest Number (30) https://pintia.cn/problem-sets/994805342720868352/problems/994805480801550336
/*/
 不是按照字典序排列就可以的，必须保证两个字符串构成的数字是最小的才行，所以cmp函数写成return a + b < b + a;的形式，保证它排列按照能够组成的最小数字的形式排列。
 /*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
string str[10010];
int visit[10010];

bool cmp(string a,string b){
    return a+b < b+a;
}

int main(){
    int n;
    string ans;
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        cin >> str[i];
    }
    sort(str, str+n,cmp);
    for (int i = 0; i<n; i++) {
        ans += str[i];
    }
    while (ans[0] == '0') {
        ans.erase(ans.begin());
    }
    if (ans.length() == 0) {
        cout << 0 << endl;
    }else
        cout << ans << endl;
    return 0;
}
