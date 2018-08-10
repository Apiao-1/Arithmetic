//https://www.nowcoder.com/profile/2575579/codeBookDetail?submissionId=28665003
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int n,x,y,z,a = 0,b,c;
    while (cin >> n) {
        cin >> x >> y >> z ;
        a = 0, b= 0, c= 0;
        for (int i=1; i<=9; i++) {
            for (int j =0 ; j<=9; j++) {
                if ((i*10000+x*1000+y*100+z*10+j) % n == 0) {
                    a = i;b = j;
                    c =(i*10000+x*1000+y*100+z*10+j) / n;
                }
            }
        }
        if (a) {
            cout << a <<" " <<  b << " " <<c <<endl;
        }else
            cout << 0 << endl;
        
    }
    return 0;
}
