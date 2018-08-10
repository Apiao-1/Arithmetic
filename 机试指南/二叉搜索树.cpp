//https://www.nowcoder.com/practice/30a0153649304645935c949df7599602?tpId=40&tqId=21539&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
string str,str2;
string a[22];

struct TreeNode{
    char val;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode(char c):val(c),lchild(NULL),rchild(NULL){}
};

void insertTree(TreeNode* root, int n){
    if (n == root -> val) {
        return ;
    }
    else if( n < root -> val){
        if(root -> lchild)
            insertTree(root -> lchild, n);
        else{
//            cout << root -> val << endl;
            root -> lchild = new TreeNode(n);
        }
    }
    else if( n > root -> val){
        if(root -> rchild)
            insertTree(root -> rchild, n);
        else{
//            cout << root -> val << endl;
            root -> rchild = new TreeNode(n);
        }
    }
}

void preOrder(TreeNode* root){
    if (!root) {
        return ;
    }
    str += root -> val;
    preOrder(root -> lchild);
    preOrder(root -> rchild);
}

void inOrder(TreeNode* root){
    
    if (!root) {
        return ;
    }
    inOrder(root -> lchild);
    str2 += root -> val;
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
    int n;
    string ori1,ori2;
    while (cin >>n) {
        for(int i = 0;i<=n;i++)
            cin >> a[i];
        TreeNode* root = new TreeNode(a[0][0]);//构造原始的树
        for (int j=1; j<a[0].length(); j++) {
            insertTree(root, a[0][j]);
        }
        preOrder(root);
        ori1 = str;
        inOrder(root);
        ori2 = str2;
        str = str2 = "";//每次赋值后需重新清空
        for(int i=1;i <=n;i++){//n条记录代比较的树
            TreeNode* tmp = new TreeNode(a[i][0]);
            for (int j=1; j<a[i].length(); j++) {
                insertTree(tmp, a[i][j]);
            }
            preOrder(tmp);
            if (ori1 == str) {
                inOrder(tmp);
                if (ori2 == str2) {
                    cout << "YES" << endl;
                }else
                    cout << "NO" << endl;
            }else
                cout << "NO" << endl;
            str = str2 = "";
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
