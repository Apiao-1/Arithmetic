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

/*/
 法二
 用非常好用的sscanf和sprintf即可解决～
 sscanf() – 从一个字符串中读进与指定格式相符的数据
 sprintf() – 字符串格式化命令，主要功能是把格式化的数据写入某个字符串中
 /*/
//#include <iostream>
//#include <string.h>
//using namespace std;
//int main() {
//    int n, cnt = 0;
//    char a[50], b[50];
//    double temp, sum = 0.0;
//    cin >> n;
//    for(int i = 0; i < n; i++) {
//        scanf("%s", a);
//        sscanf(a, "%lf", &temp);
//        sprintf(b, "%.2lf",temp);
//        int flag = 0;
//        for(int j = 0; j < strlen(a); j++) {
//            if(a[j] != b[j]) {
//                flag = 1;
//            }
//        }
//        if(flag || temp < -1000 || temp > 1000) {
//            printf("ERROR: %s is not a legal number\n", a);
//            continue;
//        } else {
//            sum += temp;
//            cnt++;
//        }
//    }
//    if(cnt == 1) {
//        printf("The average of 1 number is %.2lf", sum);
//    } else if(cnt > 1) {
//        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
//    } else {
//        printf("The average of 0 numbers is Undefined");
//    }
//    return 0;
//}
