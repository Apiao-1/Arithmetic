//1113 Integer Set Partition（25)
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
int a[100010];

int main()
{
    int n,sum1 = 0,sum2 = 0,i;
    cin >> n;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int x = n/2;
    int y = n - x;
    for(i = 0;i<x;i++){
        sum1 += a[i];
    }
    for(;i<n;i++){
        sum2 += a[i];
    }
    cout << y - x <<" " <<sum2 - sum1 << endl;
    return 0;
}
