////1057 Stack (30) https://pintia.cn/problem-sets/994805342720868352/problems/994805417945710592
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cstring>
//#include <math.h>
//#include <vector>
//#include <stack>
//using namespace std;
//
//int main(){
//    int n,tmp;
//    char cmd[100];
//    stack<int> stack;
//    vector<int> vec;
//    scanf("%d", &n);
//    for (int i = 0; i<n; i++) {
//        scanf("%s", cmd);
//        int len = stack.size();
//        if (strcmp(cmd, "Pop") == 0) {
//            if (len == 0) {
//                printf("Invalid\n");
//            }else{
//                printf("%d\n", stack.top());
//                stack.pop();
//            }
//            continue;
//        }else if(strcmp(cmd, "Push") == 0){
//            scanf("%d", &tmp);
//            stack.push(tmp);
//            continue;
//        }else if(strcmp(cmd, "PeekMedian") == 0){
//            if (len == 0) {
//                printf("Invalid\n");
//            }else{
//                vec.clear();
//                for(int j = 0;j<len;j++) {
//                    vec.push_back(stack.top());
//                    stack.pop();
//                }
//                for(int j = len-1;j>=0;j--) {
//                    stack.push(vec[j]);
//                }
//                sort(vec.begin(), vec.end());
//                if (len %2 == 0) {
//                    printf("%d\n", vec[len/2-1]);
//                }else
//                    printf("%d\n", vec[(len+1)/2-1]);
//            }
//        }
//    }
//    return 0;
//}
//树状数组+二分
#include <iostream>
#include <stack>
#define lowbit(i) ((i) & (-i))
const int maxn = 100010;
using namespace std;
int c[maxn];
stack<int> s;
void update(int x, int v) {
    for(int i = x; i < maxn; i += lowbit(i))
        c[i] += v;
}
int getsum(int x) {
    int sum = 0;
    for(int i = x; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
void PeekMedian() {
    int left = 1, right = maxn, mid, k = (s.size() + 1) / 2;
    while(left < right) {
        mid = (left + right) / 2;
        if(getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}
int main() {
    int n, temp;
    scanf("%d", &n);
    char str[15];
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(str[1] == 'u') {
            scanf("%d", &temp);
            s.push(temp);
            update(temp, 1);
        } else if(str[1] == 'o') {
            if(!s.empty()) {
                update(s.top(), -1);
                printf("%d\n", s.top());
                s.pop();
            } else {
                printf("Invalid\n");
            }
        } else {
            if(!s.empty())
                PeekMedian();
            else
                printf("Invalid\n");
        }
    }
    return 0;
}
