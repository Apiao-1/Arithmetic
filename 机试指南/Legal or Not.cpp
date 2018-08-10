//http://acm.hdu.edu.cn/showproblem.php?pid=3342
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int in[101],rel[101][101];

int main(){
    int n,m,a,b,cnt,p;
    queue<int> que;
    while (cin >> n >> m) {
        if (!n && !m) {
            break;
        }
        cnt = 0;
        memset(in, 0, sizeof(in));
        memset(rel, 0, sizeof(rel));
        for (int i =0; i<m; i++) {
            cin >> a >> b;
            if (rel[a][b] == 0) {//考虑重边的影响
                in[b] ++;
            }
            rel[a][b] = 1;//1表示有关系

        }
        //注意每次都需要先清空队列
        while (!que.empty()) {
            que.pop();
        }
        for (int i = 0; i<n; i++) {
            if (!in[i]) {//入度为0的点入栈
                que.push(i);
            }
        }
        while (!que.empty()) {
            p = que.front();
            que.pop();
            cnt++;
            for (int i = 0; i<n; i++) {
                if (rel[p][i] == 1) {
                    rel[p][i] = 0;
                    in[i] --;
                    if (!in[i]) {
                        que.push(i);
                    }
                }
            }
        }
        if(cnt == n)
            cout <<"YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
