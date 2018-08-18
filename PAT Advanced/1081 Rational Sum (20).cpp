//1081 Rational Sum (20) https://pintia.cn/problem-sets/994805342720868352/problems/994805386161274880
#include <iostream>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

struct num{
    long int numerator,denominator;
}num[101];

long int gcd(long int a,long int b){
    if (b == 0) {
        return a;
    }
    else
        return gcd(b, a%b);
}

int main() {
    int n;
    long int sum = 0;
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        scanf("%ld/%ld",&num[i].numerator,&num[i].denominator);
    }
    long int x = 1;
    for (int i = 0; i<n; i++) {
        x = num[i].denominator * x / gcd(num[i].denominator, x);
    }
    for (int i = 0; i<n; i++) {
        num[i].numerator = x / num[i].denominator *num[i].numerator;
        sum += num[i].numerator;
    }
    long int inter;
    inter = sum / x;
    sum = sum %x;
    long int tmp = gcd(x, sum);
    if (sum && tmp) {
        if (tmp < 0) {//注意该处若不取绝对值可能会导致输出的负号位置在分母上
            tmp = -tmp;
        }
        x /= tmp;
        sum /= tmp;
    }
    if (sum == 0) {
        printf("%ld\n",inter);
    }else if (inter) {
        printf("%ld %ld/%ld\n",inter,sum,x);
    }else
        printf("%ld/%ld\n",sum,x);
    
    return 0;
}
