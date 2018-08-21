//1093 Count PAT's https://pintia.cn/problem-sets/994805342720868352/problems/994805373582557184
//逻辑题，整个字符串扫描一遍，遍历字符串后对于每一A，它前面的P的个数和它后面的T的个数的乘积就是能构成的PAT的个数。然后把对于每一个A的结果相加即可
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

//int main(){
//    int cnt = 0,ans = 0;
//    string str;
//    cin >> str;
//    int len = str.length();
//这种写法会超时
//    for (int i = 0 ; i<len; i++) {
//        if (str[i] == 'P') {
//            for (int j = i+1; j<len; j++) {
//                if(str[j] == 'A')
//                    cnt++;
//                else if(str[j] == 'T' && cnt == 1){
//                    ans++;
//                    cnt = 0;
//                }
//            }
//        }
//    }
//    cout << ans%1000000007 << endl;
//    return 0;
//}
int main(){
    int cnt = 0,ans = 0,pnum,tnum;
    pnum = tnum = 0;
    string str;
    cin >> str;
    int len = str.length();
    for (int i = 0 ; i<len; i++) {
        if (str[i] == 'T') {
            tnum++;
        }
    }
    for (int i = 0 ; i<len; i++) {
        if (str[i] == 'P') {
            pnum++;
        }else if (str[i] == 'T') {
            tnum--;
        }else if (str[i] == 'A') {
            ans =(ans + (pnum*tnum)% 1000000007)% 1000000007;//这里由于pnum*tnum非常大直接写会出错，故加取模%1000000007
            //加上后还是显示答案错误，考虑到ans+(pnum*tnum)% 1000000007也会很大，再取余，AC
        }
        
    }
    cout << ans % 1000000007 << endl;
    return 0;
}

