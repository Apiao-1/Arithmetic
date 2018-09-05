//1135 Is It A Red-Black Tree（30)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
int a[35];

struct node{
    int val;
    node *lchild,*rchild;
    node(int val):val(val),lchild(NULL),rchild(NULL) {}
};

void insertTree(node *root,int val){
    if (abs(val) > abs(root->val))
    {
        if (root->rchild)
        {
            insertTree(root->rchild,val);
        }else
            root->rchild= new node(val);
    }
    else if (abs(val) <= abs(root->val))
    {
        if (root->lchild)
        {
            insertTree(root->lchild,val);
        }else
            root->lchild= new node(val);
    }
}

bool judge1(node *root){
    if (root == NULL)return true;
    if(root->val<0){
        if (root ->lchild && root->lchild->val < 0)return false;
        if (root ->rchild && root->rchild->val < 0)return false;
    }
    return judge1(root->lchild)&&judge1(root->rchild);
}

int getNum(node *root){
    if (root == NULL)return 0;
    int l = getNum(root->lchild);
    int r = getNum(root->rchild);
    return root ->val >0 ? max(l,r)+1:max(l,r);
}

bool judge2(node *root){
    if (root == NULL)return true;
    int l = getNum(root->lchild);
    int r = getNum(root->rchild);
    if (l != r)
    {
        return false;
    }
    return judge2(root->lchild)&&judge2(root->rchild);
}



int main(){
    int k,tmp,n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        fill(a,a+35,0);
        cin >> a[0];
        node *root = new node(a[0]);
        for (int j = 1; j < n; j++)
        {
            cin >> a[j];
            insertTree(root,a[j]);
        }
        int flag =  judge1(root) ;
        flag =  judge2(root) ;
        if (a[0] >= 0 && judge1(root) && judge2(root))
        {
            cout << "Yes" << endl;
        }else
            cout << "No" << endl;
        
    }
    return 0;
}
