//#include <iostream>
//#include <string>
//#include <cstring>
//
//using namespace std;
//string str,part[10];
//
//int main(){
//    int a1,a2,b1,b2,c1,c2;
//    while(cin >> str){
//        int mid = str.find("=");
//        int j = 0,flag = 0;
//        for (int i = 0; i<str.length();i++) {
//            a1 = b1 = c1 = a2 = b2 =c2 = 0;
//            while (str[i] !='+' &&str[i] !='-' &&str[i] !='*' &&str[i] !='/' &&str[i] !='=' && str[i] != '\0') {//记得要考虑是否为负数
//
//                part[j] += str[i];
//                i++;
//            }
//            j++;
//            if (str[i] == '=') {
//                flag = j;
//            }
//        }
//        for (int i = 0; i < flag; i++) {
//            if (part[i].find("x^2") != -1) {
//                int x_a1 = part[i].find("x^2");
//                if (x_a1 == 0) {
//                    a1 = 1;
//                }else
//                    for (int k = 0; k<x_a1; k++) {
//                        a1 = a1*10 + part[i][k] - '0';
//                    }
//            }else if(part[i].find("x") != -1){
//                int x_b1 = part[i].find("x");
//                if (x_b1 == 0) {
//                    b1 = 1;
//                }else
//                    for (int k = 0; k<x_b1; k++) {
//                        b1 = b1*10 + part[i][k] - '0';
//                    }
//            }else
//                for (int k = 0; part[i][k]; k++) {
//                    c1 = c1*10 + part[i][k] - '0';
//                }
//        }
//
//        for (int i = flag; i < j; i++) {
//            if (part[i].find("x^2") != -1) {
//                int x_a2 = part[i].find("x^2");
//                if (x_a2 == 0) {
//                    a2 = 1;
//                }else
//                    for (int k = 0; k<x_a2; k++) {
//                        a2 = a2*10 + part[i][k] - '0';
//                    }
//            }else if(part[i].find("x") != -1){
//                int x_b2 = part[i].find("x");
//                if (x_b2 == 0) {
//                    b2 = 1;
//                }else
//                    for (int k = 0; k<x_b2; k++) {
//                        b2 = b2*10 + part[i][k] - '0';
//                    }
//            }else
//                for (int k = 0; part[i][k]; k++) {
//                    c2 = c2*10 + part[i][k] - '0';
//                }
//        }
//        cout << a1 << b1 << c1 << a2 << b2 <<c2;
//
//    }
//    return 0;
//}

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <ctype.h>
#include <vector>
#include <cmath>

using namespace std;

int a = 0, b = 0, c = 0;

void get_coe(string str) {
    int len = str.length();
    // 为了最后时[i+1]操作不会报错
    str.append(1, '+');
    int t = 0;
    int isNegative = 1;// 是否为负数
    int afterEqual = 1;// 是否在等号右边
    for(int i = 0; i < len; i++) {
                
                if(str[i] == '=') {
                        afterEqual = -1;
                    }
                
                if(isdigit(str[i])) {
                        t = t*10 + (str[i]-'0');
                    } else if(str[i] == '-') {
                            isNegative = -1;
                        } else if(str[i] == '^') {
                                i++;
                            } else {
                                    if(str[i] == 'x' && str[i+1] == '^') {
                                            if(t == 0)  t = 1;
                                            a += t*isNegative*afterEqual;
                                        } else if(str[i] == 'x') {
                                                if(t == 0)  t = 1;
                                                b += t*isNegative*afterEqual;
                                            } else {
                                                    c += t*isNegative*afterEqual;
                                                }
                                    t = 0;
                                    isNegative = 1;
                                }
                
                if(i == len-1 && isdigit(str[i])) {
                        c += t*isNegative*afterEqual;
                        break;
                    }
            }
}

int main()
{
        string str;
        while(cin>>str) {
                get_coe(str);
                int d = b*b-4*a*c;
                if(d < 0) {
                        cout<<"No Solution"<<endl;
                    } else {
                            double t = sqrt(d);
                            double x1 = (-1*b - t)/(2*a);
                            double x2 = (-1*b + t)/(2*a);
                            printf("%.2lf %.2lf\n", min(x1, x2), max(x1, x2));
                        }
                
                a = 0; b = 0; c = 0;
            }
        return 0;
}
