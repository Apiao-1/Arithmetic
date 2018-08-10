//1020 Are They Equal (25)https://www.nowcoder.com/pat/5/problem/4113
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <cstring>
using namespace std;
int n;

string getStand(string str,int &e){
    int i = 0,tmp = n;
    string ans="0.";
    if (str[0] == '0')//去除数字前面的0
        str.erase(str.begin());
    if (str[0] == '.') {
        str.erase(str.begin());
        while (str[i] == '0') {//找到小数的首位
            str.erase(str.begin());
            e--;
        }
    }else{
        while (str[i] == '0') {//找到非小数的首位
            str.erase(str.begin());
        }
        e = (str.find('.')!=EOF)?str.find('.'):str.length();
    }
    if(str.length()==0)e=0;//处理0和0.0的情况
    for (int i=0; i<tmp; i++) {//开始处理有效数字
        if (str[i] == '.') {
            tmp++;
            continue;
        }
        if (str[i] != '\0')
            ans += str[i];
        else{
            for (; i<tmp; i++)
                ans += '0';
            break;
        }
    }
    return ans;
}

int main(){
    string a,b;
    while (cin >> n) {
        cin >> a >> b;
        int e1=0,e2=0;
        string stand_a = getStand(a,e1);
        string stand_b = getStand(b,e2);
        if (stand_a == stand_b && e1 == e2)
            cout << "YES " << stand_a <<"*10^" << e1 << endl;
        else
            cout <<"NO " <<stand_a <<"*10^" << e1 <<" "<<stand_b <<"*10^" << e2 << endl;
    }
}
