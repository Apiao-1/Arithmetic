//
//  1001 整数求和.cpp
//  Arithmetic
//
//  Created by 张朴平 on 2018/4/8.
//  Copyright © 2018年 Apiao. All rights reserved.
//
//  注意过程中溢出，用long long保证
#include <iostream>
using namespace std;

int main(){
    int n;
    long long result;
    while(cin >> n){
        result = (long long)(1 + n)*n/2;
        cout << result <<endl<<endl;
    }
    return 0;
    }
