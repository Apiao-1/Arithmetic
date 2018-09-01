//1009 Product of Polynomials（25）
//简单题，但陷阱出乎意料地多
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
using namespace std;
double ans[2030],a[1010],b[1010],tmp;

int main(){
    int k1,k2,x,ind,cnt = 0;
    cin >> k1;
    for (int i =0; i<k1; i++) {
        cin >> x >> tmp;//注意1，不一定输入没有重复
        a[x] += tmp;
    }
    cin >> k2;
    for (int i =0; i<k2; i++) {
        cin >> x >> tmp;
        b[x] += tmp;
    }
    for (int i =0; i<1010; i++) {
        if (a[i] != 0) {//此处注意输入的不一定是正数，所以不能用 >0去判断
            for (int j =0; j<1010; j++) {
                if (b[j] != 0) {
                    ind = i+j;
//                    if (ans[ind] == 0) {//不能放在中间判断，否则中途有正负数据让其变为0，再改变后，cnt数量就会错误
//                        cnt ++;
//                    }
                    ans[ind] += a[i]*b[j];
                }
            }
        }
    }
    for (int i =0; i<2030; i++) {
        if (ans[i] != 0) {
            cnt++;
        }
    }
    cout << cnt;
    for (int i =2029; i>=0; i--) {
        if (ans[i] != 0) {
            cout <<" " << i << " ";
            printf("%.01lf",ans[i]);
        }
    }
    cout << endl;
    return 0;
}

