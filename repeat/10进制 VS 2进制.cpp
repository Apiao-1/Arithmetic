//https://www.nowcoder.com/practice/fd972d5d5cf04dd4bb4e5f027d4fc11e?tpId=40&tqId=21357&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

string converse(int before, string str, int after){
    int i,j,len = int(str.length()),k,remain;
    string ans = "";
    for (i = 0; i < len; ) {
        k = 0;
        for (j = i; j < len  ; j++) {//模拟单次除法
            remain = (k*before + str[j] - '0') % after;//余数
            str[j] = (k*before + str[j] - '0') / after + '0';//商
            k = remain;
        }
        ans += char(k + '0');//一个除法做完后的商
        //由题意,正常的进制转化应加reverse
        while(str[i] == '0') i++;//做n次除法
    }
    return ans;
}

int main() {
    string a;
    while (cin >> a) {
        a = converse(10, a, 2);
//        cout << a <<endl;
        a = converse(2, a, 10);
        reverse(a.begin(), a.end());
        cout << a << endl;
        
    }
    return 0;
}

