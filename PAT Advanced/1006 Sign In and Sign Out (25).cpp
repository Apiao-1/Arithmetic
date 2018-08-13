// 1006 Sign In and Sign Out (25)https://pintia.cn/problem-sets/994805342720868352/problems/994805516654460928
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;

struct node{
    string id,in,out;
}p[1001];

int compute(string str){
    int sum=0;
    sum += (str[6] - '0')*10 + str[7] - '0';
    sum += ((str[3] - '0')*10 + str[4] - '0')*60;
    sum += ((str[0] - '0')*10 + str[1] - '0')*3600;
    return sum;
}

int main(){
    int n;
    while (cin >> n) {
        int min=999999,max=0,minFlag,maxFlag;
        for (int i = 0; i < n; i++) {
            cin >> p[i].id >> p[i].in >> p[i].out;
            if (compute(p[i].in) < min) {
                min = compute(p[i].in);
                minFlag = i;
            }
            if (compute(p[i].out) > max) {
                max = compute(p[i].out);
                maxFlag = i;
            }
        }
        cout << p[minFlag].id << " "<< p[maxFlag].id << endl;
        
    }
    return 0;
}
