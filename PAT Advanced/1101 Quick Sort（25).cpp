//1101 Quick Sort（25)
//一开始没想通为什么只要保证左边比他小即可，当时纠结了很久怎么保证右边都比他小
//对原序列sort排序，逐个比较，当当前元素没有变化并且它左边的所有值的最大值都比它小的时候就可以认为它一定是主元（很容易证明正确性的，毕竟无论如何当前这个数要满足左边都比他小右边都比他大，那它的排名【当前数在序列中处在第几个】一定不会变）
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
long long a[100010],b[100010];
vector<long long>vec;


int main(){
    int n,i,j;
    long long max;
    cin >> n;
    for (i =0; i<n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a+n);
    max = 0;
    for (i =0; i<n; i++) {
        if (b[i] == a[i] && b[i] > max) {
            vec.push_back(b[i]);
        }
        if (b[i] > max) {//点睛之笔，除了位置要相同，还要比较该数是否大于前面序列的最大值
            max = b[i];
        }
    }
    int len = vec.size();
    cout <<len<< endl;
    for (int k = 0; k<len; k++) {
        if (k == 0) {
            cout << vec[k];
        }else
            cout << " " << vec[k];
    }
    cout << endl;
    return 0;
}

