//1102 Invert a Binary Tree（25)
//注意：1.反转二叉树就是存储的时候所有左右结点都交换；2.根结点是所有左右结点中没有出现的那个结点（重要）
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
using namespace std;
int n,root,flag;

struct node{
    int lchild = -1,rchild = -1;
}tree[20];
vector<node *> vec;
int mark[20];

void inOrder(int id){
    if (id > n || id == -1) {
        return ;
    }
    inOrder(tree[id].lchild);
    if (flag == 0) {
        cout << id;
        flag = 1;
    }else
        cout << " " << id;
    inOrder(tree[id].rchild);
}


int main(){
    char r,l;
    cin >> n;
    for (int i = 0; i<n; i++) {
        cin >> r >> l;
        if (r != '-') {
            tree[i].rchild =  r -'0';
            mark[r -'0'] = 1;
        }
        if (l != '-') {
            tree[i].lchild =  l -'0';
            mark[l -'0'] = 1;
        }
    }
    for (int i = 0; i<n; i++) {
        if (!mark[i]) {
            root = i;
            break;
        }
    }
    queue<int> que;
    que.push(root);
    while (!que.empty() ) {
        int id = que.front();
        que.pop();
        if (flag == 0) {
            cout << id;
            flag = 1;
        }else
            cout << " " << id;
        if (tree[id].lchild != -1) {
            que.push(tree[id].lchild);
        }
        if (tree[id].rchild != -1) {
            que.push(tree[id].rchild);
        }
    }
    cout << endl;
    flag = 0;
    inOrder(root);
    return 0;
}

