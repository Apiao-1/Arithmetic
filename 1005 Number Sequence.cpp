//  1005 Number Sequence 找规律
//  f(n-1)与f(n-2)都是由mod7得来的，所以f(n-1)与f(n-2)的可能性都为0、1、2、3、4、5、6，也就是说，组合[f(n-1)，f(n-2)]一共只有7*7=49种可能性，所以这就出现了周期性。https://blog.csdn.net/qq_19648191/article/details/50017497

//  方法1.不计算具体循环节长度(推荐）
//#include <iostream>
//using namespace std;
//
//int main(){
//    int a,b,n,f[50];
//    f[1]=1;
//    f[2]=1;
//    while(cin >> a >> b >> n){
//        n = n%49;
//        if(a==0&&b==0&&n==0)
//            break;
//        if(n==1||n==2){
//            cout<<1<<endl;continue;
//        }else{
//            for(int i=3;i<=n;i++){
//                f[i] = (a*f[i-1] + b*f[i-2])%7;
//            }
//            cout << f[n] <<endl;
//        }
//    }
//    return 0;
//}

//   方法2.计算具体循环节长度
#include <iostream>
using namespace std;

int main(){
    int a,b,n,f[10001],length;
    f[1]=1;
    f[2]=1;
    while(cin >> a >> b >> n){
        length = 1;
        if(a==0&&b==0&&n==0)
            break;
        if(n==1||n==2){
            cout<<1<<endl;continue;
        }else{
            f[3] = (a * f[2] + b * f[1]) % 7;       //先求两项（为了避免后面都为0的情况）
            f[4] = (a * f[3] + b * f[2]) % 7;
            for(int i=5;;i++){
                f[i] = (a*f[i-1] + b*f[i-2])%7;
                if(f[i] == f[4] && f[i-1] == f[3]){
                    length = i-4;break;
                }
                    
            }
            n = (n-3)%length + 1;
            cout << f[n+2] <<endl;
        }
    }
    return 0;
}


//#include <cstdio>
//int main()
//{
//    int a,b,n;
//    int f[10001];
//    f[1] = 1;
//    f[2] = 1;
//    int s;      //记录周期
//    while (~scanf ("%d %d %d",&a,&b,&n))
//    {
//        s=1;if(a==0&&b==0&&n==0)
//            break;
//        if (n == 1 || n == 2)
//        {
//            printf ("1\n");
//            continue;
//        }
//        f[3] = (a * f[2] + b * f[1]) % 7;       //先求两项（为了避免后面都为0的情况）
//        f[4] = (a * f[3] + b * f[2]) % 7;
//        for (int i = 5 ; ; i++)
//        {
//            f[i] = (a * f[i-1] + b * f[i-2]) % 7;
//            if (f[i] == f[4] && f[i-1] == f[3])         //两项相等就开始循环
//            {
//                s = i - 4;
//                break;
//            }
//        }
//        n = (n - 3) % s + 1;      //这样的写法比上面的巧，小细节，学习一下
//        printf ("%d\n",f[2+n]);
//    }
//    return 0;
//}
