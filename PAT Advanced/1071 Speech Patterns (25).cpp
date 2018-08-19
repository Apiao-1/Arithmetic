//1071 Speech Patterns (25)https://pintia.cn/problem-sets/994805342720868352/problems/994805398257647616
//此题有几个注意点：1.map默认按键的升序排序，此处即默认为字典序，故无需多处理；2.特别注意若扫描到最后一位时，无论该位是否是字母都需将其加入map，否则可能产生最后一个单词未统计的情况
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
using namespace std;

map<string,int> cnt;//map默认按键的升序排序，此处即默认为字典序

int main(){
    string str,ans="";
    getline(cin ,str);
    int len = str.length();
    for (int i = 0; i<len ; i++) {
        if(str[i] >='A' && str[i] <='Z'){
            ans += str[i] - 'A' + 'a';
        }else if ((str[i] >='0' && str[i] <='9')||(str[i] >='a' && str[i] <='z')){
            ans += str[i];
        }else if(ans.size() > 0){
            cnt[ans]++;
            ans = "";
        }
        if(i == len - 1){//特别注意若扫描到最后一位时，无论该位是否是字母都需将其加入map，否则可能产生最后一个单词未统计的情况
            cnt[ans]++;
            ans = "";
        }
    }
    map<string, int> ::iterator itor = cnt.begin();
    int max = 0;
    string flag = "";
    for (; itor != cnt.end(); itor++) {
        if (itor->second > max) {
            max = itor->second;
            flag = itor->first;
        }
    }
    cout << flag<< " " << max << endl;
    return 0;
}
