//http://acm.hdu.edu.cn/showproblem.php?pid=1241
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[101][101];
int mark[101][101];
int go[8][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};//判断相邻的八个方向矩阵
int x,y;

void dfs(int i,int j){
    if (i >= x || j >= y || i < 0 || j <0)return ;
    if (mark[i][j]) return;
    mark[i][j] = 1;
    if (a[i][j] == '*')return;
    for (int k = 0; k<8; k++) {
        int next_x = i + go[k][0];
        int next_y = j + go[k][1];
        dfs(next_x, next_y);
    }
}

int main()
{
    while (cin >> x>> y) {
        int cnt = 0;
        if (!x && !y ) break;
        memset(mark, 0, sizeof(mark));
        for (int i = 0; i<x; i++) {
            for (int j = 0; j < y; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i<x; i++) {//遍历整个图
            for (int j = 0; j < y; j++) {
                if (!mark[i][j]) {
                    if(a[i][j] == '@'){
                        dfs(i,j);
                        cnt++;
                    }
                    mark[i][j] = 1;
                }
            }
        }
        cout << cnt << endl;
        
    }
    
    return 0;
}
