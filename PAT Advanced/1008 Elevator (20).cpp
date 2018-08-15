//1008 Elevator (20) https://pintia.cn/problem-sets/994805342720868352/problems/994805511923286016
//注意审题，第一个数字是楼层的总数，不是层号！
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int a,now = 0,sum = 0;
    cin >> a;
    while (cin >> a) {
        if (a > now) {
            sum += (a-now)*6;
        }else
            sum += (now - a)*4;
        now = a;
        sum += 5;
    }
    cout << sum << endl;
    return 0;
}


