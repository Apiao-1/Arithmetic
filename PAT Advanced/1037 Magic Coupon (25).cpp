//1037 Magic Coupon (25)https://pintia.cn/problem-sets/994805342720868352/problems/994805451374313472
//牛客网处需要把数据类型都改成long long才能过去，直接手动写sort的cmp函数还是会产生错误的地方，故默认排序，再分成两个部分判断即可
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;
long long num[100010],val[100010],sum = 0;

//bool cmp(int a,int b){//这样写比较函数还是会产生不对的地方
//    if (a * b >=0) {
//        return abs(a) > abs(b);
//    }else
//        return a > b;
//}

int main(){
    int n,m;
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        cin >> num[i];
    }
    scanf("%d",&m);
    for (int i = 0; i<m; i++) {
        cin >> val[i];
    }
    sort(num, num+n);
    sort(val, val+m);
    int i = 0,j = 0;
    while (num[i] < 0 && val[j] < 0 && i<n && j<m) {
        sum += num[i]*val[j];
        i++;j++;
    }
    i = n-1,j = m-1;
    while (num[i] > 0 && val[j] > 0 && i >= 0&&j >= 0) {
        sum += num[i]*val[j];
        i--;j--;
    }
    cout << sum << endl;
    
    return 0;
}

