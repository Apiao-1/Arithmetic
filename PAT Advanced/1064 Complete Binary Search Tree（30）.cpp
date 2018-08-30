//1064 Complete Binary Search Tree（30）https://pintia.cn/problem-sets/994805342720868352/problems/994805407749357568
//利用完全二叉树的性质就可以很简单地解决这道题,注意该方法只适用于完全二叉树！
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <queue>
using namespace std;
int n,tmp=1,a[10001],ans[10001];

void inOrder(int i){
    if (i > n) {
        return ;
    }
    inOrder(2*i);
    ans[i] = a[tmp++];
    inOrder(2*i+1);
}
void postOrder(int i){
    if (i > n) {
        return ;
    }
    postOrder(2*i);
    postOrder(2*i+1);
    if (!flag) {
        cout <<tree[i];
        flag = 1;
    }else
        cout << " " << tree[i];
    
}

int main(){
    cin >> n;
    for (int i = 1; i<=n; i++) {
        cin >> a[i];
    }
    sort(a+1, a+1+n);
    inOrder(1);
    for (int i = 1; i<=n; i++) {
        if (i == 1) {
            cout << ans[i];
        }else
            cout << " " << ans[i];
    }
//        postOrder(1);后序遍历
    cout << endl;
    return 0;
}
