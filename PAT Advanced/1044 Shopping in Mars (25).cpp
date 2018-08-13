//1044 Shopping in Mars (25) https://pintia.cn/problem-sets/994805342720868352/problems/994805439202443264
// O(n^2)复杂度会有三组测试用例超时，采用二分法将复杂度下降为O(nlgn)
// 注意超时的话，优先检查是否将输入输出换成scanf 和 printf
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;
int pay,n,mid;
vector<int> sum;

int binaryFind(int i){//二分法
    int right = n,left = i;
    while (left <= right) {
        mid = (right + left)/2;
        if (sum[mid] - sum[i] == pay)
            break;
        else if (sum[mid] - sum[i] > pay)
            right = mid - 1;
        else
            left = mid + 1;
    }
    if (sum[mid] - sum[i] < pay) {
        mid++;
    }
    return sum[mid] - sum[i];
}


int main() {
    int tmp;
    while (cin >> n >> pay) {
        vector<int> ans;
        sum.resize(n+1);
        int flag = 0,min = 9999999;
        for (int i=1; i<=n; i++) {
            scanf("%d",&sum[i]);
            sum[i] += sum[i-1];
        }
        for (int i = 0; i<=n; i++) {
            tmp = binaryFind(i);
            if (tmp == pay) {
                printf("%d-%d\n",i+1,mid);
                flag = 1;
            }else if(tmp > pay){
                if (tmp > min) {
                    continue;
                }else if (tmp < min) {
                    ans.clear();
                    min = tmp;
                }
                ans.push_back(i+1);
                ans.push_back(mid);
            }
        }
        if (!flag) {
            for (int i = 0; i< ans.size(); i+=2) {
                printf("%d-%d\n",ans[i],ans[i+1]);
            }
        }
    }
    return 0;
    
}


// //1044 Shopping in Mars (25) https://pintia.cn/problem-sets/994805342720868352/problems/994805439202443264
// // O(n^2)复杂度会有三组测试用例超时，采用二分法将复杂度下降为O(nlgn)
// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <cstring>
// #include <math.h>
// #include <vector>
// using namespace std;
// int a[100001],ans[100001],bottom[100001];//ans[i]表示从第i个节点为开始

// int main(){
//     int n,pay;
//     while (cin >> n >> pay) {
//         memset(a, 0, sizeof(a));
//         memset(ans, 0, sizeof(ans));
//         memset(bottom, 0, sizeof(bottom));
//         int sum = 0,flag = 0,min = 9999999;
//         for (int i=0; i<n; i++) {
//             scanf("%d",&a[i]);
//         }
//         for (int i=0; i<n; i++) {
//             sum = 0;
//             for (int j = i; j<n; j++) {
//                 sum += a[j];
//                 ans[i] = sum;
//                 if (sum == pay) {
//                     cout << i+1 << "-" << j+1 <<endl;
//                     flag = 1;
//                     break;
//                 }else if(sum > pay){
//                     bottom[i] = j;
//                     if (sum < min) {
//                         min = sum;
//                     }
//                     break;
//                 }
//             }
//         }
//         if (!flag) {
//             for (int i = 0; i<n; i++) {
//                 if (ans[i] == min) {
//                     cout << i+1 << "-" << bottom[i]+1 <<endl;
//                 }
//             }
//         }
//     }
//     return 0;
// }

