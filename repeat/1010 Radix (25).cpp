 //1010 Radix (25)（25 分）https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536
//做了这道题我才发现进制原来可以有诸如2792614。。那么大
//没有用二分有两个测试用例超时，得23分，正解见后文
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cstring>
//#include <math.h>
//#include <vector>
//#include <stack>
//#include <cstdio>
//#include <map>
//#include <queue>
//using namespace std;
//
//string converse(int oldBase, int newBase,string str){
//    int len = str.length(),tmp;
//    int remain = 0,divd = 0;
//    string res = "";
//    for (int i =0 ; i<len; ) {
//        divd = 0;//注意这里每次需把divd置为0，因为每次都开始一个新的除法
//        for (int j = i; j<len; j++) {
//            if (str[j] >= 'a' && str[j] <='z') {
//                tmp = str[j] - 'a' +10;
//            }else
//                tmp = str[j] - '0';
//            remain = (oldBase*divd + tmp) % newBase;
//            str[j] = (oldBase*divd + tmp) / newBase + '0';
//            divd = remain;
//        }
//        while (str[i] == '0') {
//            i++;
//        }
//        if (divd > 9) {
//            res += divd -10 +'a';
//        }else
//            res += divd + '0';
//    }
//    reverse(res.begin(), res.end());
//    return res;
//}
//
//
//int main(){
//    string n1,n2;
//    int tag,radix,flag = 0;
//    cin >> n1 >> n2 >> tag >> radix;
//    //    cout << converse(2792614, 36, "hj");
//    if (tag == 1) {
//        for (int i = 2; i<= 100000; i++) {
//            string tmp = converse(radix, i, n1);
//            if (tmp == n2) {
//                flag = 1;
//                cout << i << endl;
//                break;
//            }
//        }
//    }else{
//        for (int i = 2; i<= 100000; i++) {
//            string tmp = converse(radix, i, n2);
//            if (tmp == n1) {
//                flag = 1;
//                cout << i << endl;
//                break;
//            }
//        }
//    }
//    if (!flag) {
//        cout <<"Impossible" << endl;
//    }
//
//    return 0;
//}

//AC代码：
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;
long long convert(string n, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it = n.rbegin(); it != n.rend(); it++) {
        temp = isdigit(*it) ? *it - '0' : *it - 'a' + 10;
        sum += temp * pow(radix, index++);
    }
    return sum;
}
long long find_radix(string n, long long num) {
    char it = *max_element(n.begin(), n.end());
    long long low = (isdigit(it) ? it - '0': it - 'a' + 10) + 1;
    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(n, mid);
        if (t < 0 || t > num) high = mid - 1;
        else if (t == num) return mid;
        else low = mid + 1;
    }
    return -1;
}
int main() {
    string n1, n2;
    long long tag = 0, radix = 0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag == 1 ? find_radix(n2, convert(n1, radix)) : find_radix(n1, convert(n2, radix));
    if (result_radix != -1) {
        printf("%lld", result_radix);
    } else {
        printf("Impossible");
    }
    return 0;
}
