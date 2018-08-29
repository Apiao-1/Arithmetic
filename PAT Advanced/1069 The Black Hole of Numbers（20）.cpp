
//The Black Hole of Numbers（20）https://pintia.cn/problem-sets/994805342720868352/problems/994805400954585088
//两个点要注意，1.输入虽说是四位数，但可以是0001，固当str位数不足时要记得补0，2.特殊的测试用例，6174，要用do-while语句，否则程序什么都不会输出
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
using namespace std;

int toInt(string str){
    int len = str.length(),sum = 0;
    for (int i = 0; i<len; i++) {
        sum = 10*sum + str[i] - '0';
    }
    return sum;
}

bool cmp(int a ,int b){
    return a > b;
}

int main(){
    int num;
    cin >> num;

    do{
        if (num % 1111 == 0) {
            printf("%04d - %04d = %04d\n",num,num,0);
            break;
        }
        string str = to_string(num);
        while (str.length() < 4) {
            str += '0';
        }
        sort(str.begin(), str.end());
        int num2 = toInt(str);
        sort(str.begin(), str.end(),cmp);
        int num1 = toInt(str);
        num = num1 - num2;
        printf("%04d - %04d = %04d\n",num1,num2,num);
    } while (num != 6174);
    return 0;
}
