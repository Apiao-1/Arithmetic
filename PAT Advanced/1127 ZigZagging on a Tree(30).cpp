//1127 ZigZagging on a Tree£¨30)
//后序中序建树+层次遍历等级深度
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
vector<int> vec[35];

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
    while(que.size())
    {
        tmp = que.front();
        que.pop();
        vec[tree[tmp].depth].push_back(tmp);
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
        cin >> in[i];
    }
    for(int i = 0; i<n; i++)
    {
        cin >> post[i];
    }
    int a = 0;
    createtree(0,n-1,0,n-1,a);
    int root = post[n-1];
    tree[root].depth = 1;
    bfs(root);
    i=1;
    int flag = 1;
    while(vec[i].size()>0)
    {
        if(i % 2)
        {
            reverse(vec[i].begin(),vec[i].end());
        }
        int len = vec[i].size();
        for(int j = 0; j<len; j++)
        {
            if(flag)
            {
                cout << vec[i][j];
                flag = 0;
            }
            else
                cout <<" " << vec[i][j];
        }
        i++;
    }
    cout << endl;
    return 0;
}
