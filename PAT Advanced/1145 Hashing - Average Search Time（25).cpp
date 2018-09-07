//1145 Hashing - Average Search Time（25)
//此题需记住当建立hash表时，处理冲突的j的范围是0-tsize-1；而在查询时，范围是0-tsize；
//此外，在查询时要记得加上，如果该位置没有数那么也break；
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

bool isPrime(int num){
    if(num == 0 || num == 1)
        return false;
    for(int i=2;i*i <= num;i++){
        if(num % i == 0)
            return false;
    }
    return true;
}
int a[10010];

int main(){
    int ksize,n,m,tmp,loc,sum=0;
    cin >>ksize >>n>>m;
    while(!isPrime(ksize))ksize++;
    for(int i=0;i<n;i++){
        cin >>tmp;
        int isPut = 0;
        for(int j=0;j<ksize;j++){
            loc = (tmp + j*j)%ksize;
            if(a[loc] == 0){
                a[loc] = tmp;
                isPut = 1;
                break;
            }
        }
        if(!isPut)printf("%d cannot be inserted.\n",tmp);
    }
    for(int i=0;i<m;i++){
        cin >> tmp;
        for(int j=0;j<=ksize;j++){
            loc = (tmp + j*j)%ksize;
            sum++;
            if(a[loc] == tmp ||a[loc] == 0){
                break;
            }
        }
    }
    printf("%.1f\n",1.0*sum/m);
    
    return 0;
}
