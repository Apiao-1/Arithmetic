//https://www.nowcoder.com/practice/30a0153649304645935c949df7599602?tpId=40&tqId=21539&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode(int c):val(c),lchild(NULL),rchild(NULL){}
};

void insertTree(TreeNode* root, int n){
    if (n == root -> val) {
        return ;
    }
    else if( n < root -> val){
        if(root -> lchild)
            insertTree(root -> lchild, n);
        else{
            cout << root -> val << endl;
            root -> lchild = new TreeNode(n);
        }
    }
    else if( n > root -> val){
        if(root -> rchild)
            insertTree(root -> rchild, n);
        else{
            cout << root -> val << endl;
            root -> rchild = new TreeNode(n);
        }
    }
}

void preOrder(TreeNode* root){
    if (!root) {
        return ;
    }
    cout << root -> val << " ";
    preOrder(root -> lchild);
    preOrder(root -> rchild);
}

void inOrder(TreeNode* root){
    if (!root) {
        return ;
    }
    inOrder(root -> lchild);
    cout << root -> val << " ";
    inOrder(root -> rchild);
}

void postOrder(TreeNode* root){
    if (!root) {
        return ;
    }
    postOrder(root -> lchild);
    postOrder(root -> rchild);
    cout << root -> val << " ";
}

int main(){
    int n,temp;
    while (cin >> n) {
        cin >> temp;
        TreeNode* root = new TreeNode(temp);
        n--;
        cout << -1 << endl;
        for (int j=0; j<n; j++) {
            cin >> temp;
            insertTree(root, temp);
        }
        
//        preOrder(root);
//        cout << endl;
//        inOrder(root);
//        cout << endl;
//        postOrder(root);
//        cout << endl;
    }
    
    
    return 0;
}
