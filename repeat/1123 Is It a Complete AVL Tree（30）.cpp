//1123 Is It a Complete AVL Tree（30 分）https://pintia.cn/problem-sets/994805342720868352/problems/994805351302414336
#include <iostream>
#include <queue>
using namespace std;

struct node{
    int val;
    node *lchild,*rchild;
    node(int val):val(val),lchild(NULL),rchild(NULL) {}
};
queue<node *> q;
vector<int> vec;
int full = 1,complete = 1;


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

void order(node *root){
    q.push(root);
    while (!q.empty()) {
        node *tmp = q.front();
        q.pop();
        vec.push_back(tmp -> val);
        if (tmp->lchild) {
            if (!full) {
                complete = 0;
            }
            q.push(tmp->lchild);
        }else
            full = 0;
        if (tmp->rchild) {
            if (!full) {
                complete = 0;
            }
            q.push(tmp->rchild);
        }else
            full = 0;
    }
    
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
        order(root);
        for (int i = 0; i<vec.size(); i++) {
            if (i == 0) {
                cout << vec[i];
            }else
                cout <<" " << vec[i];
        }
        cout << endl;
        if (complete) {
            cout << "YES" << endl;
        }else
            cout << "NO" << endl;

        
    }
    return 0;
}
