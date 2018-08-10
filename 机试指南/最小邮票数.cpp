DFS解法
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int val,n,a[30],mark[30],z,ans[10001];
int flag =0;


void dfs(int sum,int cnt,int i){
    if(sum == val){
        ans[flag++] = cnt;
    }if(sum > val)
        return ;

    for(int k = i;k<n;k++)
        dfs(sum + a[k],cnt+1,k+1);//注意这里不是i+1，不然用过的点会重复再用
}


int main(){
    int cnt;
    while(cin >> val >> n){
        memset(mark,0,sizeof(mark));
        cnt = 0;
        int sum = 0;
        for(int i = 0;i<n;i++)
            cin >> a[i];
        dfs(sum,cnt,0);
        if(flag){
            int min = ans[0];
            for(int i=0;i<flag;i++)
                if(ans[i] < min)
                    min = ans[i];
                    cout << min << endl;
        }else
            cout << 0 << endl;

    }
    return 0;
}
