// 1001 A+B Format (20) https://pintia.cn/problem-sets/994805342720868352/problems/994805528788582400
//(i+1) % 3 == length % 3 && (i+1)!=length注意此处对加入逗号位置的判断，卡了很久
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

int main(){
    int a,b,i,j;
    char ans[100];
    while (cin >> a >> b) {
        i=0;
        int sum = a+ b;
        if (sum == 0) {
            cout << 0<< endl;
            continue;
        }
        if (sum < 0) {
            cout << '-';
            sum = -sum;
        }
//        string res = to_string(sum);//int型转化为string
        memset(ans, 0, sizeof(ans));
        while (sum/10) {
            ans[i++] = sum%10 + '0';
            sum /= 10;
        }
        if (sum) {
            ans[i] = sum + '0';
        }
        int length = strlen(ans);
        reverse(ans, ans+length);
        for (int i=0; i<length; i++) {
            cout << ans[i];
            if ((i+1) % 3 == length % 3 && (i+1)!=length) {
                cout << ',';
            }
        }
        cout << endl;
    }
    return 0;
}

//用to_string直接将int转化为字符串会简单多
//#include <iostream>
//using namespace std;
//int main() {
//    int a, b;
//    cin >> a >> b;
//    string s = to_string(a + b);
//    int len = s.length();
//    for (int i = 0; i < len; i++) {
//        cout << s[i];
//        if (s[i] == '-') continue;
//        if ((i + 1) % 3 == len % 3 && i != len - 1) cout << ",";
//    }
//    return 0;
//}
