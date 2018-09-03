//1115 Counting Nodes in a BST（30)
//BST建树+DFS
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
int a,b,sumHeight;

struct node{
    int val;
    node *lchild,*rchild;
    int depth;
    node(int val):val(val),lchild(NULL),rchild(NULL),depth(0) {}
};

void insertTree(node *root, int val){
    if (val > root -> val){
        if (root ->rchild) {
            insertTree(root->rchild, val);
        }else
            root->rchild = new node(val);
    }else if (val <= root -> val){
        if (root ->lchild) {
            insertTree(root->lchild, val);
        }else
            root->lchild = new node(val);
    }
}

int getHeight(node *root){
    if (root == NULL) {
        return 0;
    }
    return max(getHeight(root->lchild), getHeight(root->rchild))+1;
}

void dfs(node *root,int depth){
    if (root == NULL) {
        return ;
    }
    if (depth == sumHeight-1) {
        a++;
    }else if(depth == sumHeight)
        b++;
    dfs(root->lchild, depth+1);
    dfs(root->rchild, depth+1);
}
//其实是可以揉在一起的，不用先把树高求出来
//void dfs(node *root, int depth) {
//    if(root == NULL) {
//        maxdepth = max(depth, maxdepth);
//        return ;
//    }
//    num[depth]++;
//    dfs(root->left, depth + 1);
//    dfs(root->right, depth + 1);
//
//}

int main(){
    int n,tmp;
    cin >> n;
    cin >> tmp;
    node *root =new node(tmp);
    for (int i =1; i<n; i++) {
        cin >> tmp;
        insertTree(root,tmp);
    }
    sumHeight = getHeight(root);
    dfs(root,1);
    cout <<b<<" + " << a <<" = " << a+b << endl;
    return 0;
}
