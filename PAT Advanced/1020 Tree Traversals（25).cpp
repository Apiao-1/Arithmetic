//1020 Tree Traversals（25)
//后序中序建树+层次遍历
#include <iostream>
#include <string>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cstdio>
using namespace std;

struct node
{
    int depth;
    int lchild,rchild;
} tree[35];
int post[35],in[35];

void createtree(int s1,int e1,int s2,int e2,int &index)
{
    if(s1 > e1)
        return ;
    int root = post[e2];
    int x = 0;
    while(in[s1+x]!=root) x++;
    index = root;
    createtree(s1,s1+x-1,s2,s2+x-1,tree[root].lchild);
    createtree(s1+x+1,e1,s2+x,e2-1,tree[root].rchild);
}

void bfs(int root)
{
    int tmp;
    queue<int> que;
    
    que.push(root);
    int flag = 1;
    while(que.size())
    {
        tmp = que.front();
        que.pop();
        if(flag)
        {
            cout << tmp;
            flag = 0;
        }
        else
            cout <<" " << tmp;
        if(tree[tmp].lchild > 0)
        {
            tree[tree[tmp].lchild].depth = tree[tmp].depth+1;
            que.push(tree[tmp].lchild);
        }
        if(tree[tmp].rchild > 0)
        {
            tree[tree[tmp].rchild].depth = tree[tmp].depth+1;
            que.push(tree[tmp].rchild);
        }
    }
}

int main()
{
    int n,i;
    cin >> n;

    for(int i = 0; i<n; i++)
    {
        cin >> post[i];
    }
    for(int i = 0; i<n; i++)
    {
        cin >> in[i];
    }
    int a = 0;
    createtree(0,n-1,0,n-1,a);
    int root = post[n-1];
    tree[root].depth = 1;
    bfs(root);
    cout << endl;
    return 0;
}
