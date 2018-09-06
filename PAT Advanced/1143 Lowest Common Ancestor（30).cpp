////1143 Lowest Common Ancestor（30)
//自己做的太复杂啦，不用按传统的思路先去创建树，再去dfs记录每个节点的根节点，直接利用BST的性质即可巧妙解决：将当前结点标记为a，如果查询的两个数u和v分别在a的左、右，或者u、v其中一个就是当前a，即(a >= u && a <= v) || (a >= v && a <= u)，说明找到了这个共同最低祖先a，退出当前循环
#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, bool> mp;
int main() {
    int m, n, u, v, a;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        for(int j = 0; j < n; j++) {
            a = pre[j];
            if ((a >= u && a <= v) || (a >= v && a <= u)) break;
        }
        if (mp[u] == false && mp[v] == false)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (mp[u] == false || mp[v] == false)
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        else if (a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <string.h>
//#include <algorithm>
//#include <math.h>
//#include <vector>
//#include <map>
//#include <set>
//#include <cstdio>
//using namespace std;
//vector<int> vec[10010],tmpRoad;
//int ind = 2;
//struct node{
//    int val,id;
//    node *lchild,*rchild;
//    node(int val,int id): val(val),id(id),lchild(NULL),rchild(NULL) {}
//};
//
//
//void insertTree(node *root,int val){
//    if (val < root->val)
//    {
//        if (root -> lchild)insertTree(root->lchild,val);
//        else root->lchild = new node(val,ind++);
//    }
//    else if (val >= root->val)
//    {
//        if (root -> rchild)insertTree(root->rchild,val);
//        else root->rchild =new node(val,ind++);
//    }
//}
//
//void dfs(node *root){
//    if (root == NULL) return ;
//    vec[root->val] = tmpRoad;
//    tmpRoad.push_back(root->val);
//    if (root -> lchild) dfs(root->lchild);
//    if (root -> rchild) dfs(root->rchild);
//    tmpRoad.pop_back();
//}
//
//
//int main(){
//    int n,m,tmp,x,y;
//    cin >> n>> m;
//    cin >> tmp;
//    node *root = new node(tmp,1);
//    for (int i = 1; i < m; i++)
//    {
//        cin >> tmp;
//        insertTree(root,tmp);
//    }
//    dfs(root);
//    for (int i = 0; i < n; i++)
//    {
//        cin >> x >> y;
//        int isPrint = 0;
//        int len1 = vec[x].size();
//        int len2 = vec[y].size();
//        int findx=0,findy=0;
//        if (len1 == 0 && x != root->val)findx = 1;
//        if (len2 == 0 && y != root->val)findy = 1;
//        if (findx && findy) cout << "ERROR: "<<x << " and " <<y <<" are not found." << endl;
//        else if(findx) cout << "ERROR: "<<x << " is not found." << endl;
//        else if(findy) cout << "ERROR: "<<y << " is not found." << endl;
//        else{
//            for (int j = 0; j < len1; j++){
//                if (vec[x][j] == y)
//                {
//                    printf("%d is an ancestor of %d.\n",y,x);
//                    isPrint = 1;
//                    break;
//                }
//            }
//            if(isPrint) continue;
//            for (int j = 0; j < len2; j++){
//                if (vec[y][j] == x)
//                {
//                    printf("%d is an ancestor of %d.\n",x,y);
//                    isPrint = 1;
//                    break;
//                }
//            }
//            if(isPrint) continue;
//            for (int j = len1-1; j >=0; j--)
//                for (int k = len2-1; k>=0;k--){
//                    if(isPrint) break;
//                    if (vec[x][j] == vec[y][k])
//                    {
//                        printf("LCA of %d and %d is %d.\n",x,y,vec[x][j]);
//                        isPrint = 1;
//                        break;
//                    }
//                }
//        }
//    }
//    return 0;
//}


