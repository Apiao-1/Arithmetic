////1020 Are They Equal (25)https://www.nowcoder.com/pat/5/problem/4113
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//#include <string.h>
//#include <cstring>
//using namespace std;
//int n;
//
//string getStand(string str,int &e){
//    int i = 0,tmp = n;
//    string ans="0.";
//    if (str[0] == '0')//去除数字前面的0
//        str.erase(str.begin());
//    if (str[0] == '.') {
//        str.erase(str.begin());
//        while (str[i] == '0') {//找到小数的首位
//            str.erase(str.begin());
//            e--;
//        }
//    }else{
//        while (str[i] == '0') {//找到非小数的首位
//            str.erase(str.begin());
//        }
//        e = ((int)str.find('.')!=EOF)?(int)str.find('.'):(int)str.length();
//    }
//    if(str.length()==0)e=0;//处理0和0.0的情况
//    for (int i=0; i<tmp; i++) {//开始处理有效数字
//        if (str[i] == '.') {
//            tmp++;
//            continue;
//        }
//        if (str[i] != '\0')
//            ans += str[i];
//        else{
//            for (; i<tmp; i++)
//                ans += '0';
//            break;
//        }
//    }
//    return ans;
//}
//
//int main(){
//    string a,b;
//    while (cin >> n) {
//        cin >> a >> b;
//        int e1=0,e2=0;
//        string stand_a = getStand(a,e1);
//        string stand_b = getStand(b,e2);
//        if (stand_a == stand_b && e1 == e2)
//            cout << "YES " << stand_a <<"*10^" << e1 << endl;
//        else
//            cout <<"NO " <<stand_a <<"*10^" << e1 <<" "<<stand_b <<"*10^" << e2 << endl;
//    }
//}
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    int n, p = 0, q = 0;
    char a[10000], b[10000], A[10000], B[10000];
    scanf("%d%s%s", &n, a, b);
    int cnta = strlen(a), cntb = strlen(b);
    for(int i = 0; i < strlen(a); i++) {
        if(a[i] == '.') {
            cnta = i;
            break;
        }
    }
    for(int i = 0; i < strlen(b); i++) {
        if(b[i] == '.') {
            cntb = i;
            break;
        }
    }
    int indexa = 0, indexb = 0;
    while(a[p] == '0' || a[p] == '.') p++;
    while(b[q] == '0' || b[q] == '.') q++;
    if(cnta >= p)
        cnta = cnta - p;
    else
        cnta = cnta - p + 1;
    if(cntb >= q)
        cntb = cntb - q;
    else
        cntb = cntb - q + 1;
    if(p == strlen(a))
        cnta = 0;
    if(q == strlen(b))
        cntb = 0;
    while(indexa < n) {
        if(a[p] != '.' && p < strlen(a))
            A[indexa++] = a[p];
        else if(p >= strlen(a))
            A[indexa++] = '0';
        p++;
    }
    while(indexb < n) {
        if(b[q] != '.' && q < strlen(b))
            B[indexb++] = b[q];
        else if(q >= strlen(b))
            B[indexb++] = '0';
        q++;
    }
    if(strcmp(A, B) == 0 && cnta == cntb)
        printf("YES 0.%s*10^%d", A, cnta);
    else
        printf("NO 0.%s*10^%d 0.%s*10^%d" , A, cnta, B, cntb);
    return 0;
}
