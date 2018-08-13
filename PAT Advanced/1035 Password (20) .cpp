// 1035 Password (20) https://pintia.cn/problem-sets/994805342720868352/problems/994805454989803520
//注意审题，要查找四个字符（更快的做法是扫一遍去匹配四种情况，不使用.find和.replace）
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;

struct node{
    string id,psd;
}p[1001];

int main(){
    int n,ans[1001];
    while (cin >> n) {
        int changeNum = 0,flag=0,j=0;
        for (int i=0; i<n; i++) {
            flag = 0;
            string str="";
            cin >> p[i].id >> str;
            while (str.find('0') != EOF) {
                str[str.find('0')] ='%';
                if (!flag) {
                    changeNum++;
                    flag = 1;
                }
            }
            while (str.find('1') != EOF) {
                str[str.find('1')] ='@';
                if (!flag) {
                    changeNum++;
                    flag = 1;
                }
            }
            while (str.find('l') != EOF) {
                str[str.find('l')] ='L';
                if (!flag) {
                    changeNum++;
                    flag = 1;
                }
            }
            while (str.find('O') != EOF) {
                str[str.find('O')] ='o';
                if (!flag) {
                    changeNum++;
                    flag = 1;
                }
            }
            p[i].psd = str;
            if (flag) {
                ans[j++] = i;
            }
        }
        if (!changeNum) {
            if (n == 1) {
                cout << "There is 1 account and no account is modified" << endl;
            }else
                cout << "There are " << n << " accounts and no account is modified" << endl;
        }else{
            cout << changeNum << endl;
            for (int i=0; i<changeNum; i++) {
                cout << p[ans[i]].id << " " << p[ans[i]].psd << endl;
            }
        }
    }
    return 0;
}

