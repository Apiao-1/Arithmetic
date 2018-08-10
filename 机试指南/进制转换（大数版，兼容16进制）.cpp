#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <math.h>
#include <algorithm>

using namespace std;

string converse(int old,int ne, string a){
    int len = a.length(),divd = 0,remain = 0;
    string ans;
    for(int j = 0;j<len;) {
        remain = 0;
        for (int i = j; i<len ; i++) {//大整数模拟单个除法
            int tmp = a[i] - '0';
            if (a[i] >=  'A' && a[i] <='z') {
                tmp = a[i]-'A' + 10;
            }
            divd =(remain*old + tmp)%ne;//余数
            a[i]  =(remain*old + tmp)/ne + '0';//商
            remain = divd;//必须要有第三个变量，不然会出现在做本次除法时上一次的结果已被改变的情况
        }
        ans += divd + '0';
        while(a[j] == '0')j++;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;

}


int main(){
    string a,b;
    while(cin >> a){
        int len = a.length();
        for (int i = 2; i<len; i++) {
            b += a[i];
        }
        b = converse(16,10,b);
        cout << b << endl;
        
    }
    return 0;
}




