//1084 Broken Keyboard（20 分）https://pintia.cn/problem-sets/994805342720868352/problems/994805382902300672
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

int main(){
    string in,out;
    map<char, int> hash;
    cin >> in >> out;
    int len1 = in.length(),len2 = out.length();
    for (int i = 0; i<len2; i++) {
         out[i] = toupper(out[i]);
    }
    for (int i = 0,j=0; i<len1; i++) {
        in[i] = toupper(in[i]);
        if (in[i] == out[j]) {
            j++;
        }else{
            if (hash.count(in[i]) == 0) {
                cout << in[i];
                hash[in[i]]++;
            }
        }
    }
    cout << endl;
    return 0;
}

//更简单的写法，直接扫一遍s2，在s2中寻找s1当中的每一个字符
//#include <iostream>
//#include <cctype>
//using namespace std;
//int main() {
//    string s1, s2, ans;
//    cin >> s1 >> s2;
//    for (int i = 0; i < s1.length(); i++)
//        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
//            ans += toupper(s1[i]);
//    cout << ans;
//    return 0;
//}
