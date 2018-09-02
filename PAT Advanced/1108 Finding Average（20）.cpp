//1108 Finding Average（20）
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
using namespace std;

int main(){
    int n,cnt = 0;
    float num,sum = 0;
    string str;
    vector<string>er;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> str;
        int len = str.length(),pointNum = 0,flag = 1,loc;
        for (int j = 0; j<len; j++) {
            if (!isdigit(str[j]) && str[j] !='.' && str[j] !='-') {
                er.push_back(str);
                flag = 0;
                break;
            }
            if (str[j] == '.') {
                loc = j;
                pointNum++;
                if (pointNum > 1) {
                    er.push_back(str);
                    flag = 0;
                    break;
                }
            }
        }
        if (len - loc >3) {
            er.push_back(str);
            flag = 0;
        }
        if (flag == 0) {
            continue;
        }
        num = stof(str);
        if (num < -1000 || num >1000) {
            er.push_back(str);
            continue;
        }
        sum += num;
        cnt++;
    }
    int len = er.size();
    for (int i = 0; i<len; i++) {
        cout << "ERROR: " << er[i] << " is not a legal number"<<endl;
    }
    if (cnt == 0) {
        cout<<"The average of 0 numbers is Undefined" << endl;
    }else if(cnt == 1){
        cout << "The average of " << cnt << " number is ";
        printf("%.2f\n",1.0*sum/cnt);
    }
    else{
    cout << "The average of " << cnt << " numbers is ";
    printf("%.2f\n",1.0*sum/cnt);
    }
    
    
    return 0;
}
