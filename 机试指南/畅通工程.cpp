//https://www.nowcoder.com/practice/4878e6c6a24e443aac5211d194cf3913?tpId=40&tqId=21457&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <math.h>
#include <algorithm>
#include <cstring>
using namespace std;

int findroot(int *tree,int a){//查找a节点所在树的树根
    int tmp = a,x;
    while (tree[a] != -1) {
        a = tree[a];
    }
    while (tree[tmp] != -1) {//压缩路径
        x = tree[tmp];
        tree[tmp] = a;
        tmp = x;
    }
    return a;
}

int main(){
    int n,m;
    while (cin >> n >>m) {
        if (n == 0) {
            break;
        }
        int tree[n+1],a,b,count = 0;
        memset(tree, -1, sizeof(tree));
        for (int i=0; i<m; i++) {
            cin >> a >> b;
            a = findroot(tree, a);
            b = findroot(tree, b);
            if (a != b) {//注意始终是树根合并
                tree[a] = b;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (tree[i] == -1) {
                count ++;
            }
        }
        cout << --count << endl;
    }
    return 0;
}
