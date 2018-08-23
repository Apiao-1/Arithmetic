//1065 A+B and C (64bit)（20 分）
/*/
 方法一，longlong类型再判断sum是否溢出
 因为A、B的大小为[-2^63, 2^63]，用long long 存储A和B的值，以及他们相加的值sum：
 如果A > 0, B < 0 或者 A < 0, B > 0，sum是不可能溢出的
 如果A > 0, B > 0，sum可能会溢出，sum范围理应为(0, 2^64 – 2]，溢出得到的结果应该是[-2^63, -2]是个负数，所以sum <= 0时候说明溢出了
 如果A < 0, B < 0，sum可能会溢出，同理，sum溢出后结果是大于0的，所以sum >= 0 说明溢出了
 
 这里需特别注意sum = 0的溢出判断，不然PAT最后一组测试用例过不去
 /*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i<=n; i++) {
        long long a,b,c;
        cin >> a >> b >> c;
        long long sum = a+b;
        if (a > 0 && b > 0 && sum <=0) {//处理正溢出的情况
            printf("Case #%d: true\n",i);
        }else if(a <0 && b <0 && sum >= 0)//处理负溢出的情况
            printf("Case #%d: false\n",i);
        else if(sum > c)
            printf("Case #%d: true\n",i);
        else
            printf("Case #%d: false\n",i);
    }
    
    
    return 0;
}
//方法二，直接用long double类型，求出的sum不会溢出
//#include<iostream>
//using namespace std ;
//int main()
//{
//    int T ;
//    cin >> T ;
//    for( int i = 1; i <= T; ++i )
//    {
//        long double a, b, c, ans ;
//        cin >> a >> b >> c ;
//        cout << "Case #"<< i <<": " << (a+b>c ? "true" : "false") << endl ;
//    }
//    return 0 ;
//}
