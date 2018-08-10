//https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6?tpId=40&tqId=21334&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;


int main() {
    int  n,sum,j;
    long long tmp;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        for (int i = 0; i < n; i++) {
            sum = 0;
            cin >> tmp;
            for (j = 1; j < sqrt(tmp); j++) {
                if (tmp % j == 0) {
                    sum ++ ;
                }
            }
            if (j == sqrt(tmp)) {
                sum = sum*2 +1;
            }else
                sum *= 2;
            cout << sum << endl;
            
        }
    }
    
    
    return 0;
}
