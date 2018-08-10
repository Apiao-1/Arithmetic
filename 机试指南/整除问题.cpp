//https://www.nowcoder.com/questionTerminal/8e29045de1c84d349b43fdb123ab586a
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int ans1[10001],ans2[10001];


int main() {
    int n,a;
    while (cin >> n >> a) {
        int A = sqrt(a);
        //对a进行质因数分解
        for (int i = 2; i < A ; i++) {
            while(a % i == 0) {
                ans2[i]++;
                a /= i;
            }
        }
        if (a) {
            ans2[a]++;
        }
        //在n！中找其质因数的个数(1，2，3……n相乘，对于数i，（n/i，n/i*i，n/i*i*i……之和）即为其贡献的i的个数)
        
        for (int i = 2; i < n ; i++) {
            int k = 1,tmp;
            tmp = int(pow(i, k));
            while (n/tmp) {
                ans1[i] += n/tmp;
                k++;
                tmp = int(pow(i, k));
            }
        }
        int min = ans1[2] / ans2[2];
        for (int i=2; i<10001; i++) {
            if (ans2[i] == 0) {
                continue;
            }
            if (ans1[i]/ans2[i] < min)
                min =ans1[i]/ans2[i];
        }
        cout << min << endl;

        
    }
    return 0;
}
