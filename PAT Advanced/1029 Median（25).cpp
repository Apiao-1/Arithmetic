//1029 Median（25)
//一般的做法会报内存超限的错误，用类似归并排序的思想，值得注意的是当第二个序列扫完后，第一个序列很长可能没有走完，而mid在第一个序列之中，所以之后要把第一个序列走完
//思想没问题，但有一个测试点过不了，24
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
using namespace std;
vector<int> vec,a;

int main() {
    int n,m,tmp,cnt = 0;
    int j=0;
    cin >> n;
    for (int i = 0; i<n; i++) {
        scanf("%d",&tmp);
        a.push_back(tmp);
    }
    cin >> m;
    int mid = (n+m+1)/2;
    for (int i = 0; i<m; i++) {
        scanf("%d",&tmp);
        while (tmp > a[j]) {
            cnt++;
            if (cnt == mid) {
                cout << a[j] << endl;
                return 0;
            }
            j++;
        }
        cnt++;
        if (cnt == mid) {
            cout << tmp << endl;
            break;
        }
    }
    for (; j<=n; j++) {
        cnt++;
        if (cnt == mid) {
            cout << a[j] << endl;
        }
    }
    
}

//#include <iostream>
//using namespace std;
//int k[200005];
//int main(){
//    int n, m, temp, count = 0;
//    cin >> n;
//    for (int i = 1; i <= n; i++)
//        scanf("%d", &k[i]);
//    k[n + 1] = 0x7fffffff;
//    cin >> m;
//    int midpos = (n + m + 1) / 2, i = 1;
//    for (int j = 1; j <= m; j++) {
//        scanf("%d", &temp);
//        while (k[i] < temp) {
//            count++;
//            if (count == midpos) cout << k[i];
//            i++;
//        }
//        count++;
//        if (count == midpos) cout << temp;
//    }
//    while (i <= n) {
//        count++;
//        if (count == midpos) cout << k[i];
//        i++;
//    }
//    return 0;
//}
