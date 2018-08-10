//http://acm.hdu.edu.cn/showproblem.php?pid=2064
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

unsigned long long hanoi(int n){//注意返回数值过大导致的WA
    if (n == 1) {
        return 2;
    }
    return 3*hanoi(n-1) + 2;
    
}

int main()
{
    int n;
    while(cin >> n)
        cout << hanoi(n) << endl;
    
    return 0;
}
