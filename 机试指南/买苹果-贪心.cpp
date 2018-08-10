//贪心算法
//最开始均使用容量为8的袋子装，余下的个数看能不能用6的装
//不行的话，容量为8袋子数-1，回溯
//https://www.nowcoder.com/practice/61cfbb2e62104bc8aa3da5d44d38a6ef?tpId=85&tqId=29856&tPage=2&rp=2&ru=/ta/2017test&qru=/ta/2017test/question-ranking

#include <iostream>
using namespace std;

int main (){
    int n,bag,i,flag;
    while (cin >> n) {
        flag = 1;
        bag = n/8;//8个装的袋子数max
        for (i = bag;i>=0;i--){
            if((n - 8*i)%6 == 0){
                cout << i +(n - 8*i)/6  << endl;
                flag = 0;
                break;
            }
        }
        if(flag)
            cout << -1<<endl;
    }
    return 0;
}
