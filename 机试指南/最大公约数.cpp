
#include <iostream>
#include <cstring>
using namespace std;

int gcd(int a, int b){//greast common divisor，递归形式
    if (b == 0)
        return a;
    else
        return gcd(b, a%b);

}

int gcd1(int a, int b){//非递归形式
    while (b) {
        int t = a%b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    int a,b;
    while(cin >> a >> b){
        a = gcd1(a, b);
        cout << a <<endl;
        
    }
    return 0;
}
