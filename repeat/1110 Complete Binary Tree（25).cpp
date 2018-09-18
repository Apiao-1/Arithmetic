//1110 Complete Binary Tree（25)
//完全二叉树的判断（区别于满二叉树）
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
using namespace std;
int mark[22];
vector<int> ans;

struct node{
    int lchild = -1,rchild = -1;
}p[22];

int main(){
    int n,root,tmp,cnt = 0;
    string a,b;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> a >> b;
        if (a != "-") {
            p[i].lchild = stoi(a);
            mark[p[i].lchild] = 1;
        }
        if (b != "-") {
            p[i].rchild = stoi(b);
            mark[p[i].rchild] = 1;
        }
    }
    for (int i = 0; i<n; i++) {
        if (mark[i] == 0) {
            root = i;
            break;
        }
    }
    queue<int> que;
    que.push(root);
    while (!que.empty()) {
        tmp = que.front();
        if (tmp == -1) {
            break;
        }
        que.pop();
        cnt++;
        ans.push_back(tmp);
        que.push(p[tmp].lchild);
        que.push(p[tmp].rchild);
    }
    if (cnt == n) {
        cout << "YES " << ans[cnt-1]<<endl;
    }else
        cout << "NO " << root<<endl;
    return 0;
}
