//1061 Dating（20） https://pintia.cn/problem-sets/994805342720868352/problems/994805411985604608
//终于看懂了题，一开始对题目中的“since the first common capital English letter (case sensitive) shared by the first two strings is the 4th capital letter D”，产生了误解（我说原序列中相等的位置明明是6呀，怎么会是4呢）
//每次输出时分秒时注意控制%02d，不能光控制了分，不控制时
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    string a,b,c,d;
    string week[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    cin >> a >> b >> c >> d;
    int tmp,flag;
    char h,date;
    int len1 = a.length(),len2 = c.length();
    for (int i = 0; i<len1; i++) {
        if (a[i] == b[i] && (a[i] >='A' && a[i] <= 'G')) {
            date = a[i];
            tmp = i;
            break;
        }
    }
    for (int i = tmp+1; i<len1; i++) {
        if (a[i] == b[i] && ((a[i] >='A' && a[i] <= 'N') || (a[i] >='0' && a[i] <= '9'))) {
            h = a[i];
            break;
        }
    }
    for (int i = 0; i<len2; i++) {
        if (isalpha(c[i]) && c[i] == d[i]) {
            flag = i;
            break;
        }
    }
    if (h >= 'A' && h <= 'N') {
        h = h - 'A' + 10 + '0';
    }
    cout << week[date - 'A']<< " ";
    printf("%02d:%02d\n",h - '0',flag);
    return 0;
}
