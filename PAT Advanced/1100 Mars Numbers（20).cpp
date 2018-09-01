//1100 Mars Numbers（20)
//揉在一起考虑复杂了，因为数据明确说小于169，也就是说只有两位，直接根据len判断是否存在高位，进一步取高位低位即可
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
string a[2][13]={
    {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"},
    {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"}
    
};
    
int main(){
    int n,num,low,high,j,k;
    string str,tmp;
    scanf("%d\n",&n);
    for (int i = 0; i<n; i++) {
        getline(cin, str);
        int len = str.length();
        if (isdigit(str[0])) {
            num = stoi(str);
            low = num % 13;
            high = num / 13;
            if (high > 0 && low > 0) {
                cout << a[1][high-1] <<" " <<a[0][low];
            }else if(high == 0)
                cout <<a[0][low];
            else if(low == 0)
                cout<<a[1][high-1];
        }else{
            int sum = 0,flag = 0;
            for (int i=0; i<len; i+=4) {
                tmp ="";
                if (str.substr(i,4) == "tret") {
                    sum = 0;
                    break;
                }
                tmp = str.substr(i,3);
                bool find = 0;
                for (j = 0; j<2; j++) {
                    for (k = 0; k<12; k++) {
                        if (a[j][k] == tmp) {
                            find = 1;
                            break;
                        }
                    }
                    if (find) {
                        break;
                    }
                }
                if (j == 1) {
                    sum += 13*(k+1);
                }else{
                    sum += k;
                }
            }
            if (!flag) {
                cout << sum;
                flag = 1;
            }else{
                cout << " " << sum;
            }
        }
        cout << endl;
    }
    return 0;
}


//#include <iostream>
//#include <string>
//#include <cctype>
//using namespace std;
//string a[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
//string b[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
//void func1(string s) {
//    int len = s.length(), num = 0;
//    for (int i = 0; i < len; i++)
//        num = num * 10 + (s[i] - '0');
//    if (num / 13) {
//        cout << b[num / 13];
//        if (num % 13) cout << ' ' << a[num % 13];
//    } else {
//        cout << a[num % 13];
//    }
//}
//void func2(string s) {
//    int len = s.length(), num = 0;
//    if (len == 4) {
//        cout << 0;
//        return;
//    } else if (len == 3) {
//        for (int i = 1; i <= 12; i++) {
//            if (s == a[i]) {
//                cout << i;
//                return;
//            }
//            if (s == b[i]) {
//                cout << i * 13;
//                return;
//            }
//        }
//    }
//    else {
//        string temp1 = s.substr(0, 3), temp2 = s.substr(4, 3);
//        for (int i = 1; i <= 12; i++) {
//            if (temp1 == b[i]) num += i * 13;
//            if (temp2 == a[i]) num += i;
//        }
//        cout << num;
//    }
//    return;
//}
//int main() {
//    int n;
//    cin >> n;
//    getchar();
//    for (int i = 0; i < n; i++) {
//        string s;
//        getline(cin, s);
//        if (isdigit(s[0]))
//            func1(s);
//        else
//            func2(s);
//        cout << endl;
//    }
//    return 0;
//}
