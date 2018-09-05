//1138 Postorder Traversal（25)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
int pre[50010],in[50010],post[50010],flag;

void getPost(int s1,int e1,int s2,int e2,int s3,int e3){
    if (s1 > e1 || flag)
    {
        return ;
    }
    int root = pre[s1];
    int x =0;
    while(in[s2+x] != root ) x++;
    post[e3] = root;
    if (e3 == 0)
    {
        cout << root << endl;
        flag = 1;
    }
    getPost(s1+1,s1+x,s2,s2+x-1,s3,s3+x-1);
    getPost(s1+1+x,e1,s2+x+1,e2,s3+x,e3-1);
    
}

int main(){
    //freopen("a.txt","r",stdin);千万记得要把这句话给注释掉
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&pre[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&in[i]);
    }
    getPost(0,n-1,0,n-1,0,n-1);
    //for (int i = 0; i < n; i++)
    //{
    //    cout << post[i] << " ";
    //}
    //cout << post[0] << endl;
    return 0;
}
