//http://acm.hdu.edu.cn/showproblem.php?pid=2035
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int main() {
    int a,b,ans;
    while (cin >> a >> b) {
        if (!a && !b) {
            break;
        }
        ans = 1;
        while (b) {//二分求a的b次，即相当于求b二进制位数，详见王道机试宝典P104
            if (b %2 == 1) {
                ans = ans * a %1000;
            }
            a = a*a % 1000;
            b /= 2;
        }
        
        
        cout << ans <<endl;
    }
    
}
