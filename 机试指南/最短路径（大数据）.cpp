
//https://www.nowcoder.com/profile/2575579/codeBookDetail?submissionId=28678396
#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int tree[101];
//define后不能加分号
#define MAX 99999999

int findroot(int a){
    int tmp = a,x;
    while (tree[a] != -1) {
        a = tree[a];
    }
    while(tree[tmp] != -1){
        x = tree[tmp];
        tree[tmp] = a;
        tmp = x;
    }
    return a ;
    
}

int lpow(int a, int b){
    int x = 1;
    while (b--) {
        x = (a*x)%100000;
    }
    return x;
}

int main(){
    int n,m,a,b,p,q,ans[101][101],dist;
    for (int i = 0; i<101; i++) {
        for (int j = 0; j<101; j++) {
            ans[i][j] = MAX;
        }
    }
    while (cin >> n >> m) {
        memset(tree, -1, sizeof(tree));
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            p = findroot(a);
            q = findroot(b);
            if (p != q) {
                tree[p] = q;
                dist = lpow(2,i) % 100000;
                ans[a][b] = ans[b][a] = dist;
            }
        }
        //floyd 算法
//        for(int i = 0;i<n;i++){
//            for (int j = 0; j < n; j++) {
//                for (int k = 0; k < n; k++) {
//                    if (ans[i][k] == MAX || ans[k][j] == MAX) {
//                        continue;
//                    }
//                    if (ans[i][j] > ans[i][k] + ans[k][j]){
//                        ans[i][j] = (ans[i][k] + ans[k][j])  % 100000;
//                    }
//                }
//            }
//        }
        int mark[n+1];
        memset(mark, 0, sizeof(mark));
        for (int i =1; i<n; i++) {
            int min = MAX,flag = 0;
            for (int j = 1; j<n; j++) {
                if (ans[0][j] < min && !mark[j]){
                    min = ans[0][j];
                    flag = j;
                }
            }
            mark[flag] = 1;
            for (int j = 1; j<n; j++) {
                if (!mark[j] && ans[0][j] > ans[0][flag] + ans[flag][j]) {
                    ans[0][j] = (ans[0][flag] + ans[flag][j])%100000;
                }
            }
        }
        for (int i = 1; i< n; i++) {
            if (ans[0][i] == MAX)
                cout << -1 << endl;
            else
                cout << ans[0][i] << endl;
        }
    }
    return 0;
}
