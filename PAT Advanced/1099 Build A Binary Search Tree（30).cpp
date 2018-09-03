//1099 Build A Binary Search Tree（30)
//利用BST的性质，中序遍历进行赋值
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
int val[110],ind;

struct node{
    int val;
    int lchild,rchild;
}p[110];

void inOrder(int root){
    if (root == -1) {
        return ;
    }
    inOrder(p[root].lchild);
    p[root].val = val[ind++];
    inOrder(p[root].rchild);
}

int main(){
    int n,tmp,a,b;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> p[i].lchild >> p[i].rchild;
    }
    for (int i = 0; i<n; i++) {
        cin >> val[i];
    }
    sort(val, val+n);
    inOrder(0);
    queue<int> que;
    que.push(0);
    int flag = 1;
    while (!que.empty()) {
        int id = que.front();
        que.pop();
        if (flag == 1) {
            cout << p[id].val;
            flag = 0;
        }else
            cout << " " << p[id].val;
        if (p[id].lchild != -1) {
            que.push(p[id].lchild);
        }
        if (p[id].rchild != -1) {
            que.push(p[id].rchild);
        }
    }
    cout << endl;
    return 0;
}
