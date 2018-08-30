//1078 Hashing（25）https://pintia.cn/problem-sets/994805342720868352/problems/994805389634158592
//1、此处不是双向的二次平方探测法，注意题目里写了单项(with positive increments only)
//2、回忆筛法求素数的写法（注意与判断素数的区别，判断素数的条件写成j*j <= num⭐️,此处的等号不能漏）
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
int mark[11000],ans[11000];
vector<int>prime;

void getPrime(){
    for (int i = 2; i<11000; i++) {
        if (!mark[i]) {
//注意此处筛法求素数不用再判断这个数字是不是素数了
//            int flag = 1;
//            for (int j = 2; j*j <= i; j++) {
//                if (i % j == 0) {
//                    flag = 0;
//                    break;
//                }
//            }
//            if (flag) {
//                prime.push_back(i);
//            }
            prime.push_back(i);
            for (int k = i; k<11000; k+=i) {
                mark[k] = 1;
            }
        }
    }
}

int main(){
    int size,n,tmp;
    getPrime();
    cin >> size >> n;
    int len = prime.size();
    for (int i = 0; i<len; i++) {
        if (prime[i] == size) {
            break;
        }else if(prime[i] > size){
            size = prime[i];
            break;
        }
    }
    int flag = 1,result = 0;
    for (int i = 0; i<n; i++) {
        cin >> tmp;
        result = 0;
        tmp %= size;
        if (ans[tmp] == 0) {
            ans[tmp]++;
            result = 1;
        }else{
            for (int k = 1;k < size;k++) {
                int p =(tmp + k*k)%size;
                if (ans[p] == 0) {
                    ans[p]++;
                    tmp = p;
                    result = 1;
                    break;
                }
            }
        }
        if (result) {
            if (flag) {
                cout << tmp;
                flag = 0;
            }else
                cout <<" " << tmp;
        }else{
            cout <<" -";
        }
    }
    cout << endl;
    return 0;
}


//一开始写了双向的
//#include <iostream>
//#include <string>
//#include <vector>
//#include <math.h>
//using namespace std;
//int mark[1100],ans[1100],tag[1100];
//vector<int>prime;
//
//int main(){
//    int size,n,tmp;
//    getPrime();
//    cin >> size >> n;
//    int len = prime.size();
//    for (int i = 0; i<len; i++) {
//        if (prime[i] == size) {
//            break;
//        }else if(prime[i] > size){
//            size = prime[i];
//            break;
//        }
//    }
//    int flag = 1,result = 0;
//    for (int i = 0; i<n; i++) {
//        cin >> tmp;
//        result = 0;
//        tmp %= size;
//        if (ans[tmp] == 0) {
//            ans[tmp]++;
//            result = 1;
//        }else{
//            int k = 1;
//            while (k < size) {
//                int p =(tmp + k*k)%size;
//                int q =(size + tmp - k*k)%size;
//                if (ans[p] == 0) {
//                    ans[p]++;
//                    tmp = p;
//                    result = 1;
//                    break;
//                }
//                else if (ans[q] == 0) {
//                    ans[q]++;
//                    tmp = q;
//                    result = 1;
//                    break;
//                }
//                k++;
//            }
//        }
//        if (result) {
//            if (flag) {
//                cout << tmp;
//                flag = 0;
//            }else
//                cout <<" " << tmp;
//        }else{
//            cout <<" -";
//        }
//    }
//    cout << endl;
//    return 0;
//}
