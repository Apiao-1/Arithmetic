//http://acm.hdu.edu.cn/showproblem.php?pid=1016
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int i,n,mark[21],ans[21];
int prime[13] = {2,3,5,7,11,13,17,19,23,29,31,37,41};

bool checkprime(int n){//判断其是否为素数
    for (int i =0; i<13; i++) {
        if (n == prime[i]) {
            return 1;
            break;
        }
    }
    return 0;
}


void dfs(){
    if (i > 1) {
        if(!checkprime(ans[i] + ans[i-1])) return ;
    }
    if (i == n && !checkprime(ans[i] + ans[1]))return ;
    else if(i==n){//输出结果
        int flag = 1;
        for (int i = 1; i<=n; i++) {
            if (flag) {
                cout << ans[i];
                flag = 0;
            }
            else
                cout << " "<<ans[i] ;
        }
        cout << endl;
        return ;
    }
        
    ++i;
    for (int j=2; j<=n; j++) {
        if (!mark[j]) {//若该数字未被使用
            mark[j] = 1;
            ans[i] = j;
            dfs();
            mark[j] = 0;
        }
    }
    --i;//该位所有的数字都已尝试，回溯到上一层
}


int main()
{
    int num = 1;
    while(cin >> n){
        memset(mark, 0, sizeof(mark));
        memset(ans, 0, sizeof(mark));
        mark[1] = ans[1] = 1;
        i = 1;
        printf("Case %d:\n",num++);
        dfs();
        cout << endl;
    }
    
    
    return 0;
}
