//1027 Colors in Mars (20) https://pintia.cn/problem-sets/994805342720868352/problems/994805470349344768
//巧妙的写法，因为0~168的十进制转换为13进制不会超过两位数，所以这个两位数为(num / 13)(num % 13)构成的数字
#include <cstdio>
using namespace std;
int main() {
    char c[14] = {"0123456789ABC"};
    printf("#");
    for(int i = 0; i < 3; i++) {
        int num;
        scanf("%d", &num);
        printf("%c%c", c[num/13], c[num%13]);
    }
    return 0;
}

//复习一遍任意进制转换的写法
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cstring>
//#include <math.h>
//#include <vector>
//using namespace std;
//
//string change(int oldBase,int newBase,string num){
//    int len = num.length(),k,remain;
//    string ans="";
//    for (int i=0; i<len;) {
//        k = 0;
//        for (int j = i; j<len; j++) {
//            remain = (k*oldBase + num[j] - '0') % newBase;
//            num[j] = (k*oldBase + num[j] - '0') / newBase + '0';
//            k = remain;
//        }
//        if (k >= 0 && k<=9) {
//            ans += k + '0';
//        }else
//            ans += k - 10 + 'A';
//        while (num[i] == '0') {
//            i++;
//        }
//    }
//    reverse(ans.begin(), ans.end());
//    return ans;
//}
//
//int main(){
//    string r,g,b;
//    while (cin >> r >> g >> b) {
//        r = change(10,13,r);
//        g = change(10,13,g);
//        b = change(10,13,b);
//        if (r.length() == 1) {
//            r = '0' + r;
//        }
//        if (g.length() == 1) {
//            g = '0' + g;
//        }
//        if (b.length() == 1) {
//            b = '0' + b;
//        }
//        cout << "#" << r+g+b << endl;
//    }
//    return 0;
//}
