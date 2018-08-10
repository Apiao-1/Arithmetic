//http://acm.hdu.edu.cn/showproblem.php?pid=1253
//未AC
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int r[55][55][55];
int a,b,c,t;
int go[6][3]={
    1,0,0,
    -1,0,0,
    0,1,0,
    0,-1,0,
    0,0,1,
    0,0,-1
};
struct node{
    int a,b,c;
    int t;
    node(int a,int b,int c,int t): a(a),b(b),c(c),t(t){}
};


int BFS(){
    queue<node> q;
    q.push(node(0,0,0,0));
    r[0][0][0] = 1;//记得标记起点
    while (q.size()) {
        node now = q.front();
        q.pop();
        if (now.t > t) {
            continue;
        }
        if (now.a == a-1 && now.b == b-1 && now.c == c-1 ) {
            return now.t;
        }
        for (int i = 0; i <6; i++) {
            int na =now.a + go[i][0];
            int nb =now.b + go[i][1];
            int nc =now.c + go[i][2];
            if (!r[na][nb][nc] && na >=0 &&na<a&&nb>=0&&nb<b&&nc>=0&&nc<c){
                r[na][nb][nc] = 1;
                q.push(node(na,nb,nc,now.t+1));
            }
        }
    }
    return -1;
}

int main(){
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d%d%d%d",&a,&b,&c,&t) ;
        for (int i=0; i<a; i++) {
            for (int j=0; j<b; j++) {
                for (int k=0; k<c; k++) {
                    scanf("%d",&r[i][j][k]);
                }
            }
            int ans = BFS();
            printf("%d\n",ans);
        }
        
    }
    
    return 0;
}
