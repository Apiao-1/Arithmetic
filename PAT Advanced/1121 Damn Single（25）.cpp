//1121 Damn Single（25）
//此题需注意编号00000，固初始的id不能初始化为0；同时需注意输出位0时的格式
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
using namespace std;
int id[100001],mark[100001];
vector<int> ans;

int main(){
    int n,m,tmp,cnt=0;
    fill(id, id+100001, -2);
    scanf("%d",&n);
    for (int i = 0; i<n; i++) {
        scanf("%d",&tmp);
        scanf("%d",&id[tmp]);
        id[id[tmp]] = tmp;
    }
    scanf("%d",&m);
    for (int i = 0; i<m; i++) {
        scanf("%d",&tmp);
        if (id[tmp] != -2) {
            mark[tmp]++;
            if (mark[id[tmp]] == 1) {
                mark[id[tmp]]++;
                mark[tmp]++;
                cnt+=2;
            }
        }else
            mark[tmp] = -1;
    }
    cout << m - cnt << endl;
    int flag = 1;
    for (int i =0; i<100001; i++) {
        if ((mark[i] == 1 || mark[i] == -1) && flag) {
            printf("%05d",i);
            flag = 0;
        }else if(mark[i] == 1 || mark[i] == -1)
            printf(" %05d",i);
    }
    return 0;
}

