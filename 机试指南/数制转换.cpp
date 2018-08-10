//https://www.nowcoder.com/profile/2575579/codeBookDetail?submissionId=28491319
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
    int a,b,ans[1001],j,length;
    long long tmp;
    string n;
    while (cin >> a >> n >> b) {
        if (n == "0") {
            cout << 0 <<endl;
            break;
        }
        tmp = j = 0;
        //将a进制数先转化成10进制
        length = (int)n.length() - 1;
        for (int i = 0; n[i]; i++,length--) {
            if (n[i] >= '0' && n[i] <= '9' ) {
                tmp += (n[i] - '0')*(int)pow(a, length);
            }else if (n[i] >= 'a' && n[i] <= 'z')
                tmp += (n[i] - 'a' + 10)*(int)pow(a, length);
            else
                tmp += (n[i] - 'A' + 10)*(int)pow(a, length);
        }
        
        //将10进制转化成b进制
        while(tmp){
            ans[j++] = tmp % b;
            tmp /= b;
        }
        j--;
        for (; j>=0; j--) {
            if(ans[j] < 10)
                cout << ans[j];
            else
                cout << char(ans[j] - 10 + 'A');
        }
        cout << endl;
    }
        return 0;
}
