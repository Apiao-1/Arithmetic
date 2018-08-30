//1086 Tree Traversals Again（25) https://pintia.cn/problem-sets/994805342720868352/problems/994805380754817024
/*/
此题一开始错处理成了还原完全二叉树再进行后序遍历，因为题目中未明确说是一颗完全二叉树，故解法错误，正解：栈实现的是二叉树的中序遍历（左根右），而每次push入值的顺序是二叉树的前序遍历（根左右），所以该题可以用二叉树前序和中序转后序的方法做
/*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int in[50],pre[50],post[50],n,ind1,ind,tree[50],flag;

//不一定是完全二叉树，所有不能用这个写法
//void inOrder(int i){
//    if (i > n) {
//        return ;
//    }
//    inOrder(2*i);
//    tree[i] = a[ind++];
//    inOrder(2*i+1);
//}

void getPost(int s1,int e1,int s2,int e2,int s3,int e3){
    if (s1 > e1) {
        return ;
    }
    int root = pre[s1];
    post[e3] = root;
    int x = 0;
    while (in[s2+x] != root) {
        x++;
    }
    getPost(s1+1, s1+x, s2, s2+x-1, s3, s3+x-1);
    getPost(s1+x+1, e1, s2+x+1, e2, s3+x, e3-1);
}

int main(){
    cin >> n;
    char str[10];
    int tmp;
    stack<int> s;
    for (int i = 1; i<= 2*n;i++) {
        scanf("%s",str);
        if (str[1] == 'u') {
            cin >> tmp;
            s.push(tmp);
            pre[ind1++] = tmp;
        }else if(str[1] == 'o') {
            tmp = s.top();
            s.pop();
            in[ind++] = tmp;
        }
    }
    getPost(0,n-1,0,n-1,0,n-1);
    for (int i = 0; i<n; i++) {
        if (i == 0) {
            cout << post[i];
        }else
            cout << " " << post[i];
    }
    cout <<endl;
    return 0;
}
