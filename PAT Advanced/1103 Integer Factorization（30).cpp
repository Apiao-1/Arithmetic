//1103 Integer Factorization（30)
//dfs,可优化的剪枝条件：1.当且仅当tmpSum <= n时，进行下一层的DFS，而不要进入下一层DFS发现不满足条件再返回，这样开销会比较大；2.pow函数花销大，可事先将其pow之后的值计入数组
//一个测试点答案错误，29分，找不到原因
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
using namespace std;
int n,t,e,maxCnt,ans[200],limit,tmpSum;
vector<int> res,powList;

void dfs(int sum,int curNum, int curT,int sumCnt){
    if (sum == n && curT == t) {
        if (sumCnt >= maxCnt) {
            maxCnt = sumCnt;
            res.clear();
            for (int j = 0; j<t; j++) {
                res.push_back(ans[j]);
            }
        }
        return ;
    }
    if (curT >= t) {
        return ;
    }
    for (int i = curNum; i <= limit; i++) {
        ans[curT] = i;
        tmpSum = sum+powList[i];
        if (tmpSum <= n) {
            dfs(tmpSum, i, curT+1, sumCnt+i);
        }else
            return ;
    }
}

bool cmp(int a,int b){
    return a > b;
}

int main(){
    scanf("%d%d%d",&n,&t,&e);
    limit = 0;
    int x = pow(limit, e);
    while (x <=n) {
        limit++;
        powList.push_back(x);
        x = pow(limit, e);
    }
    dfs(0, 1, 0, 0);
    sort(res.begin(), res.end(),cmp);
    int len = res.size();
    if (len == 0) {
        printf("Impossible");
    }else
        for (int i = 0; i<len; i++) {
            if (i == 0) {
                printf("%d = %d^%d",n,res[i],e);
            }else
                printf(" + %d^%d",res[i],e);
        }
    printf("\n");
    return 0;
}

