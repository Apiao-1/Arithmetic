//https://www.nowcoder.com/practice/9255c05d45b8406c9b588d7c57aa920b?tpId=40&tqId=21466&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int ans[101],a,b,m,i;
    unsigned long long sum;
    while(cin >> m){
        if (!m) {
            break;
        }
        cin >>a >> b;
        sum = a+b;
        i = 0;
        if (!sum) {
            cout << 0 << endl;
            break;
        }
        while (sum) {
            ans[i++] = sum % m;
            sum /= m;//注意这里也是除以要转换的进制
        }
        for (i--;i > -1; i--) {
            cout << ans[i];
        }
        cout << endl;
        
    }
    return 0;
}
