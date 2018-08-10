//https://www.nowcoder.com/practice/20426b85f7fc4ba8b0844cc04807fbd9?tpId=40&tqId=21338&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int status[10001];//0表示为素数，1表示不是素数
int ans[10001],length;


void getNum(){
    status[0] = status[1] = length = 0;
    for (int i=2; i<10001; i++) {
        if (!status[i]) {
            ans[length++] = i;
            int  k = i;
            for (int j = k*i;j < 10001;j = k*i) {
                status[j] = 1;
                k++;
            }
        }
    }
}

int main() {
    int  tmp,count[10001],another,sum;
    getNum();
    while (cin >> tmp) {
        memset(count , 0, sizeof(count));
        sum = 0;
        for (int j = 0; ans[j] < tmp && ans[j] > 0; j++) {//仅仅小于tmp不行，因为超过10000范围之后的ans[i]为0
            while (tmp % ans[j] == 0) {
                count[ans[j]]++;
                sum++;
                tmp /= ans[j];
            }
        }
        if (tmp != 1) {
            another = tmp;//注意这里是判断tmp不为1，则必存在唯一一个大于10000的素数
            sum++;
        }
        cout << sum << endl;
        
    }
    
    
    return 0;
}

//解法2
//#include <iostream>
//#include <cmath>
//using namespace std;
//int main(){
//        //这题的关键：
//        //1、是sqrt,可以极大减少复杂度，若是到方根N仍大于1，则必还有且只还有1个质因数
//        //2、每次瞬间整除都可帮助减少遍历范围
//        long M=100;
//        while(cin>>M)
//            {
//                    long count=0;
//                        for(long j=2;j<=sqrt(M);j++)
//                            {
//                                 while(M%j==0)
//                                     {
//                                             M=M/j;
//                                             count++;
//                                         }
//                                 if(M<=1)break;
//                                }
//                    if(M>1)count++;
//                    cout<<count<<endl;
//                }  
//        return 0;
//}
//不用判断是不是质数的原因：
//因为任何一个合数都能被一个比它小的质数整除。所以当我们用小质数去分解这个给定的数时，我们已经把他的合数因子分解了。
//       或者从反面去说，如果出现了一个合数a能整除这个数M，那显然在j =a之前应该有一个质数p < a 能把a整除，而之前反复地用M去除以p直到p不能再整除M 程序才往下执行，那怎么会后来又出现了M中一个合数因子a能被p整除呢？这显然矛盾了。
//        从而可以推出，程序中能整除M的数都是质数。
