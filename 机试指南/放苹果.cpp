#include <iostream>
using namespace std;

int func(int m, int n){
    if(m == 0 || n == 1)
        return 1;
    else if (m < n)
        return  func(m,m);
    else
        return func(m,n-1) + func(m-n,n);
}


int main(){
    int n,m;
    while(cin >>m >>n){
        cout <<func(m,n)<< endl;
    }
    return 0;
}
