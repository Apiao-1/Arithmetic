//1122 Hamiltonian Cycle（25）
//哈密顿回路，统计入度出度
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
using namespace std;
int e[210][210],du[210];

int main(){
    int n,m,a,b,q,t,tmp,j;
    int list[210],mark[210];
    cin >> n >> m;
    for (int i = 0; i<m; i++) {
        cin >> a >>b ;
        e[a][b] = e[b][a] = 1;
    }
    cin >> q;
    for (int i = 0; i<q; i++) {
        cin >> t;
        fill(list, list+210, 0);
        fill(mark, mark+210, 0);
        fill(du, du+210, 0);
        for (j = 0; j<t; j++) {
            cin >> list[j];
        }
        for (j = 1; j<t; j++) {
            if (e[list[j]][list[j-1]] > 0) {
                du[list[j]]++;
                du[list[j-1]]++;
            }
        }
        int flag = 0;
        for (int j =1; j <=n; j++) {
            if (du[j] != 2) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            cout << "NO" <<endl;
        }else
            cout << "YES" <<endl;
        
    }
    return 0;
}

