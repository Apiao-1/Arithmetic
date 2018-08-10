// PAT advanced 1048

//方法一、如下优化O（n^2）还是会有两组数据超时，得分20;
//思想：传统的方法用一个数组去记录所有的银币值，二重循环遍历判断是否有相等的硬币，期间添加剪枝函数 a[i] + maxNum >= toPay
//#include <iostream>
//using namespace std;
//
//int max(int *a){
//    int max = a[0];
//    for(int j =0;a[j];j++){
//        if (a[j] > max)
//            max = a[j];
//    }
//    return max;
//}
//
//int main(){
//    int n,toPay,a[100001],maxNum,index1,index2,v1 = 0,v2 = 0,resultCount=0;
//    while(cin >> n >> toPay){
//        for (int i=0;i<n;i++){
//            cin >> a[i];
//        }
//        resultCount = 0;
//        maxNum = max(a);
//        for (int i=0;i<n;i++){
//            if (a[i] + maxNum >= toPay){
//                for (int k=i+1;k<n;k++){
//                    if (a[i] + a[k] == toPay){
//                        index1 = (a[i] < a[k]) ? i:k;
//                        index2 = (a[i] > a[k]) ? i:k;
//                        if (resultCount == 0){
//                            v1 = index1;
//                            v2 = index2;
//                            resultCount ++;
//                        }
//                        else if(a[index1] < a[v1]){
//                            v1 = index1;
//                            v2 = index2;
//                        }
//                    }
//                }
//            }
//        }
//        if (resultCount)
//            cout << a[v1] <<" "<< a[v2] <<endl;
//        else
//            cout <<"No Solution"<< endl;
//    }
//
//}

//法二、查询表，用数组a[5001]记录所有币值信息及对应的个数，数组索引即为币值，对应的值为此金额对应的硬币个数
#include <iostream>
using namespace std;

int main(){
    int a[5002]={0},n,toPay,temp,j;
    bool flag=1;
    while(cin >> n >> toPay){
        flag = 1;
        for (int i=0;i<n;i++){
            cin >> temp;
            a[temp]++;
        }
        for(j=0;j<=toPay-j;j++){
            a[j]--;
            a[toPay-j]--;//保证两枚硬币面额相同时，也能正确判断其数量
            if (a[j]>=0 && a[toPay-j]>=0){
                cout << j <<" "<< toPay-j <<endl;
                flag = 0;
                break;
            }
//            a[j]++; 这里无需再把不符合的硬币数还回来，因为这种情况之后不会再判断了
//            a[toPay-j]++;
        }
        if (flag)
            cout <<"No Solution"<< endl;
    }
}
