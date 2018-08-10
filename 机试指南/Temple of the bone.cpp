//http://acm.hdu.edu.cn/showproblem.php?pid=1241
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char a[10][10];
int mark[10][10];
int go[4][2]={1,0,-1,0,0,1,0,-1};//判断相邻的八个方向矩阵
int x,y,sx,sy,ex,ey,t,T,ans;

void dfs(int i,int j){
    if (ans) {//已有答案直接结束
        return;
    }
    if (t > T)return ;//大于限定时间直接结束
    if (i == ex && j == ey && t == T) {
        ans = t;
        return ;
    }
    if (i >= x || j >= y || i < 0 || j <0)return ;
    if (mark[i][j]) return ;
    mark[i][j] = 1;
    if (a[i][j] == 'X')return ;
    for (int k = 0; k<4; k++) {
        int next_x = i + go[k][0];
        int next_y = j + go[k][1];
        t++;
        dfs(next_x, next_y);
        t--;
    }
    mark[i][j] = 0;
}

int main()
{
    while (cin >> x>> y >>T) {
        if (!x && !y && !T) break;
        t = 0;
        ans = 0;
        memset(mark, 0, sizeof(mark));
        for (int i = 0; i<x; i++) {
            for (int j = 0; j < y; j++) {
                cin >> a[i][j];
                if(a[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }else if(a[i][j] == 'D'){
                    ex = i;
                    ey = j;
                }
            }
        }
        if((sx + sy)%2 == (ex+ey)%2 ){//奇偶剪枝，起点终点坐标和奇偶性相同时
            if(T % 2 != 0){
                cout << "NO" << endl;
                continue;
            }
        }
        else if((sx + sy)%2 != (ex+ey)%2 )
            if(T % 2 != 1){
                cout << "NO" << endl;
                continue;
            }
        dfs(sx,sy);
        if (ans) {
            cout << "YES" << endl;
        }else
            cout <<"NO"<< endl;
        
    }
    
    return 0;
}
