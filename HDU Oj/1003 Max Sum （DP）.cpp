//  1003 Max Sum （DP）
//  b[j]为以第j项为尾的最大子段和，构造dp方程 b[j] = max{b[j-1]+a[j](b[j-1]>0),a[j](b[j-1]<0)}

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int round,num,a[100001],index,max,b,indexBegin,indexFinal;
//    memset(a,0 , 100001);
    cin >> round;
    for (int i=0;i<round;i++){
        max=-999;b=-999;indexBegin=0;indexFinal=0;index=0;//注意初始化max不能为0，考虑字符串全为负数的情况
        cin >> num;
        for(int j=0;j<num;j++){
            cin >> a[j];
            if(b >=0) b+=a[j];//dp
            else {
               b = a[j];
               index = j;
            }
            if ( b>max){
                max = b;
                indexFinal = j;
                indexBegin = index;
            }
        }
        cout << "Case " << i+1 << ":"<<endl;
        cout << max <<" "<<indexBegin+1<<" "<<indexFinal+1<<endl;
        if(i<round-1)
            cout << endl;
    }
    return 0;
}
