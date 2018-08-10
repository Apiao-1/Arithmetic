//http://acm.hdu.edu.cn/showproblem.php?pid=1495
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int s,n,m,mark[101][101][101];

struct node{
    int a,b,c;
    int t;
};

void poul(int a,int b,int &now_a,int &now_b){//a，b为两个容器的容量，now_a,now_b为目前容器中的的可乐,a往b中倒
    if(b - now_b >= now_a ){//a全部倒入b中，注意其中语句的顺序
        now_b += now_a;
        now_a = 0;
    }else{//a只能倒部分
        now_a = now_a - b + now_b;
        now_b = b;
    }
}

int BFS(){
    queue<node> q;
    node node = {s,0,0,0};
    mark[s][0][0] = 1;
    q.push(node);
    while(!q.empty()){
        struct node now = q.front();
        q.pop();
        int a = now.a;
        int b = now.b;
        int c = now.c;
        poul(s, n, a, b); //s倒入n中
        if (!mark[a][b][c]) {
            mark[a][b][c] = 1;
            if ((a == s/2.0 && b == s/2.0)||(a == s/2.0 && c == s/2.0)||(c == s/2.0 && b == s/2.0) ) {
                return now.t+1;
            }
            struct node newnode = {a,b,c,now.t+1};
            q.push(newnode);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        poul(n, s, b, a); //s倒入m中
        if (!mark[a][b][c]) {
            mark[a][b][c] = 1;
            if ((a == s/2.0 && b == s/2.0)||(a == s/2.0 && c == s/2.0)||(c == s/2.0 && b == s/2.0)  ) {
                return now.t+1;
            }
            struct node newnode = {a,b,c,now.t+1};
            q.push(newnode);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        poul(s, m, a, c); //s倒入m中
        if (!mark[a][b][c]) {
            mark[a][b][c] = 1;
            if ((a == s/2.0 && b == s/2.0)||(a == s/2.0 && c == s/2.0)||(c == s/2.0 && b == s/2.0) ) {
                return now.t+1;
            }
            struct node newnode = {a,b,c,now.t+1};
            q.push(newnode);
        }
        
        a = now.a;
        b = now.b;
        c = now.c;
        poul(m, s, c, a); //s倒入m中
        if (!mark[a][b][c]) {
            mark[a][b][c] = 1;
            if ((a == s/2.0 && b == s/2.0)||(a == s/2.0 && c == s/2.0)||(c == s/2.0 && b == s/2.0) ) {
                return now.t+1;
            }
            struct node newnode = {a,b,c,now.t+1};
            q.push(newnode);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        poul(m, n, c, b); //s倒入m中
        if (!mark[a][b][c]) {
            mark[a][b][c] = 1;
            if ((a == s/2.0 && b == s/2.0)||(a == s/2.0 && c == s/2.0)||(c == s/2.0 && b == s/2.0) ) {
                return now.t+1;
            }
            struct node newnode = {a,b,c,now.t+1};
            q.push(newnode);
        }
        a = now.a;
        b = now.b;
        c = now.c;
        poul(n, m, b, c); //s倒入m中
        if (!mark[a][b][c]) {
            mark[a][b][c] = 1;
            if ((a == s/2.0 && b == s/2.0)||(a == s/2.0 && c == s/2.0)||(c == s/2.0 && b == s/2.0) ) {
                return now.t+1;
            }
            struct node newnode = {a,b,c,now.t+1};
            q.push(newnode);
        }
    }
    return 0;
}

int main(){
    while (cin >> s>> n>>m) {
        if (!s && !n && !m) {
            break;
        }
        memset(mark, 0, sizeof(mark));
        int t = BFS();
        if (t) {
            cout << t << endl;
        }else
            cout << "NO" << endl;
    }
}
