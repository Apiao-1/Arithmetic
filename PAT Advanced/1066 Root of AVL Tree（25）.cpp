//1066 Root of AVL Tree（25 分）https://pintia.cn/problem-sets/994805342720868352/problems/994805404939173888
#include <iostream>
using namespace std;

struct node{
    int val;
    node *lchild,*rchild;
    node(int val):val(val),lchild(NULL),rchild(NULL) {}
};

node *rotateRight(node *root){
    node *tmp = root ->lchild;
    root ->lchild = tmp ->rchild;
    tmp -> rchild = root;
    return tmp;
}

node *rotateLeft(node *root){
    node *tmp = root ->rchild;
    root ->rchild = tmp ->lchild;
    tmp -> lchild = root;
    return tmp;
}

node *rotateLeftRight(node *root){
    root -> lchild = rotateLeft(root -> lchild);
    return rotateRight(root);
}

node *rotateRightLeft(node *root){
    root -> rchild = rotateRight(root -> rchild);
    return rotateLeft(root);
}

int getHigh(node *root){
    if (root == NULL) {
        return 0;
    }
    return max(getHigh(root->lchild), getHigh(root->rchild))+1;
}

node *insert(node *root,int tmp){
    if (!root) {
        root = new node(tmp);
    }
    else if (tmp > root -> val) {
        root->rchild = insert(root->rchild, tmp);
        if (getHigh(root->rchild) - getHigh(root->lchild) == 2)
            root = tmp > root->rchild->val ? rotateLeft(root):rotateRightLeft(root);
    }else if(tmp < root -> val){
        root->lchild = insert(root->lchild, tmp);
        if (getHigh(root->lchild) - getHigh(root->rchild) == 2)
            root = tmp < root->lchild->val ? rotateRight(root):rotateLeftRight(root);
    }
    return root;
}

int main(){
    int n,tmp;
    while(scanf("%d", &n) != EOF){
        cin >> tmp;
        node *root = new node(tmp);
        for (int i = 1; i<n; i++) {
            cin >> tmp;
            root = insert(root,tmp);
        }
        cout << root -> val << endl;
        
    }
    return 0;
}
