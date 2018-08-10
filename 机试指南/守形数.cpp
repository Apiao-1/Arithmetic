//https://www.nowcoder.com/practice/99e403f8342b4d0e82f1c1395ba62d7b?tpId=40&tqId=21549&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n,ans,tmp,i;
    while (cin >> n) {
        tmp = n;
        i = 0;
        while (tmp) {
            tmp /= 10;
            i++;
        }
        ans = (n*n % (int)pow(10,i) == n)? 1:0 ;
        if (ans) {
            cout << "Yes!" <<endl;
        }else
            cout << "No!" <<endl;
    }
    
    return 0;
}
