//1144 The Missing Number（20)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
int a[100011];

int main(){
    int n,tmp;
    cin >>n;
    for(int i = 0;i<n;i++){
        cin >>tmp;
        if(tmp <= 0 || tmp > 100010)continue;
        a[tmp]++;
    }
    for(int i = 1;i<100010;i++){
        if(a[i] == 0){
            cout <<i << endl;
            break;
        }
    }
    return 0;
}
