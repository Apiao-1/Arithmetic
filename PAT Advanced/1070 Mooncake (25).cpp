//1070 Mooncake (25) https://pintia.cn/problem-sets/994805342720868352/problems/994805399578853376
//贪心算法
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;

struct mooncake{
    float num;//注意审题，题目没说num一定是整数
    float price,val;
}cake[1010];

bool cmp(struct mooncake a,struct mooncake b){
    return a.val > b.val;
}

int main() {
    int n,d;
    scanf("%d%d",&n,&d);
    for (int i = 0; i<n; i++) {
        scanf("%f",&cake[i].num);
    }
    for (int i = 0; i<n; i++) {
        scanf("%f",&cake[i].price);//注意输入是%f
        cake[i].val = cake[i].price / cake[i].num;
    }
    sort(cake, cake+n, cmp);
    float ans = 0;
    for (int i = 0; i<n; i++) {
        if (d <= 0) {
            break;
        }
        if (cake[i].num >= d) {
            ans += d*cake[i].val;
            d = 0;
            break;
        }else{
            ans += cake[i].price;
            d -= cake[i].num;
        }
    }
    printf("%.2f\n",ans);
    return 0;
}
