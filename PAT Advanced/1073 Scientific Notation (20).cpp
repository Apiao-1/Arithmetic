//1073 Scientific Notation (20) https://pintia.cn/problem-sets/994805342720868352/problems/994805395707510784
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main(){
    string str;
    while (cin >> str) {
        int loc = str.find("E");
        char flag_e = str[loc+1];
        int num,len = str.length(),e=0,a,i;
        if (str[0] == '-') {
            cout << str[0];
        }
        for (int i = loc+2; i<len; i++) {
            e = 10*e + str[i] - '0';
        }
        a = loc - 3;//str.find(".")一定等于2
        
        if (flag_e == '+') {
            num = e - a;//计算添加0的数量
            if (num >= 0) {
                for (int i = 1; i<loc; i++) {
                    if (str[i] != '.') {
                        cout << str[i];
                    }
                }
                for (int i = 0; i<num; i++) {
                    cout << '0';
                }
            }else{
                for (int i = 1; i<loc; i++) {
                    if (i == loc + num)
                        cout <<".";
                    if (str[i] != '.') {
                        cout << str[i];
                    }
                }
            }
        }else{
            cout << "0.";
            if (str[1] > '0') {
                num = e -1;
            }else
                num = e;
            for(i = 0;i<num;i++){
                cout << '0';
            }
            for (int j = 1; j<loc; j++) {
                if (str[j] != '.') {
                    cout << str[j];
                }
            }
        }
        cout << endl;
    }
    return 0;
}
