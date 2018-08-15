//1051 Pop Sequence (25) https://pintia.cn/problem-sets/994805342720868352/problems/994805427332562944
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int m,n,k;
    scanf("%d%d%d", &m,&n,&k);
    int a[1010];
    for (int i = 0; i<k; i++) {
        stack<int> stack;//注意栈未初始化带来的错误
        for (int j = 0; j<n; j++) {
            scanf("%d",&a[j]);
        }
        int len = 0;
        for (int j = 1;j <= n;j++) {
            stack.push(j);
            while (stack.size() > 0 && stack.top() == a[len]) {
                stack.pop();
                len++;
            }
            if (stack.size() == m)
                break;
            
        }
        if (len == n) {
            printf("YES\n");
        }else
            printf("NO\n");
    }
    
    
    return 0;
}
