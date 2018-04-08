//
//  1002 大整数相加.cpp
//  Arithmetic
//
//  Created by 张朴平 on 2018/4/8.
//  Copyright © 2018年 Apiao. All rights reserved.
//
//  1002 A + B Problem II
//  未添加容错处理（负数&&非数字字符）


#include <iostream>
using namespace std;
#include <string>

int main(int argc, const char * argv[]) {
    string a,b,result;
    int round,cFlag;
    cin >> round;
    for(int i=0;i<round;i++){
        cFlag = 0;
        for(int i=0;i<round;i++){
            cin >> a >> b;
            cout << "case "<<i + 1<<":"<<endl;
            cout << a << " + " <<b<<" = ";
            if(a.length()<b.length()){
                result = b;
                b = a;
                a = result;
            }
            int m=(int)a.length()-1;
            int n=(int)b.length()-1;
            result =a;
            for(;m>=0;m--){
                if(n>=0){
                    if(a[m] + b[n] - '0' + cFlag>'9'){
                        result[m] =a[m] + b[n] -'0'+ cFlag - 10;
                        cFlag = 1;
                    }else{
                        result[m] = a[m] + b[n] + cFlag - '0';
                        cFlag = 0;
                    }
                    n--;
                }else{
                    if(a[m] + cFlag>'9'){
                        result[m] = a[m] + cFlag - 10;
                        cFlag = 1;
                    }
                    else{
                        result[m] = a[m] + cFlag;
                        cFlag = 0;
                    }
                }
            }
            if(cFlag){
                result.insert(0,"1");
            }
            cout<<result <<endl;
            if(i<round-1)
                cout<<endl;
        }
    }
    return 0;
}

