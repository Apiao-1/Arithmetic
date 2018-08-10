//https://www.nowcoder.com/profile/2575579/codeBookDetail?submissionId=28758353
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n,i,a[100];
    while (cin >> n) {
        memset(a, 0, sizeof(a));
        a[1] = 1;
        a[2] = 2;
        if (n > 2){
            for(i=3;i<=n;i++){
                a[i] = a[i-1] + a[i-2];
            }
        }
        cout << a[n] << endl;
    }
    return 0;
}
