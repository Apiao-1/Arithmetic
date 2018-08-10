//http://acm.hdu.edu.cn/showproblem.php?pid=1285
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int in[501],rel[501][501];

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
        for (int i = 1; i<=n; i++) {
            if (!in[i]) {//入度为0的点入栈
                que.push(i);
                in[i] = -1;
                break;
            }
        }
        int flag = 1;
        while (!que.empty()) {
            p = que.front();
            que.pop();
            if (flag) {
                cout << p;
                flag = 0;
            }else
                cout <<" " << p;
            cnt++;
            for (int i = 1; i<=n; i++) {
                if (rel[p][i] == 1) {
                    rel[p][i] = 0;
                    in[i] --;
                }
            }
            for (int j = 1; j<=n; j++) {
                if (!in[j]) {
                    que.push(j);
                    in[j] = -1;
                    break;//保证每次queue只有一个节点
                }
            }
        }
        cout << endl;
    }
    return 0;
}
