//1125 Chain the Ropes（25)
//贪心算法，注意审题，是所有绳子都要用上，每次减半
#include <iostream>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstdio>
using namespace std;
float a[10010];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ;i<n;i++){
        scanf("%f",&a[i]);
    }
    sort(a,a+n);
    for(int i = 1 ;i<n;i++){
        a[i] = (a[i] + a[i-1])/2;
    }
    int ans = (int)a[n-1];//直接舍去
    // printf("%.0f\n",(a[n-1]-0.5));//会四舍五入
    cout << ans << endl;
    return 0;
}
