// PAT Basic 1083 是否存在相等的差 (20)
#include <iostream>
using namespace std;

int main(){
    int n,a[10001],result[10000]={0},index;
    while(cin >> n){
        for (int i = 1;i<=n ;i++){
            cin >> a[i];
            index = (a[i]-i > 0)? a[i]-i:i-a[i];
            result[index]++;
        }
        for (int i = n;i>=0 ;i--){
            if (result[i] > 1)
                cout << i << " "<<result[i]<<endl;
        }
        
        
    }
}


