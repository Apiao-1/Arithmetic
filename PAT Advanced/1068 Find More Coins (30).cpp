// 1068 Find More Coins (30)（30 分） https://pintia.cn/problem-sets/994805342720868352/problems/994805402305150976
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;
int a[102],ans[1001],toPay,num;
bool flag=0;

void dfs(int sum,int k,int num){//sum表示当前的面值和，k表示当前的金币面额，num表示ans中金币的个数
    if (flag == 1) {//flag为1表示已找到
        return ;
    }
    if (sum == toPay) {
        flag = 1;
        int j;
        for (j=0; j<num-1; j++) {
            cout << ans[j] <<" ";
        }
        cout << ans[j] << endl;
        return ;
    }
    for (int i=k; i<102; i++) {//按金币的面额dfs
        if (a[i] > 0) {
            if (sum + i >toPay) {
                continue;
            }
            a[i]--;
            ans[num] = i;
            dfs(sum+i, i, num+1);
            a[i]++;
        }
    }
    return ;
}

int main(){
    int n,temp;
    while(cin >> n >> toPay){
        memset(a, 0, sizeof(a));
        for (int i=0;i<n;i++){
            cin >> temp;
            if (temp > 101) {
                continue;
            }
            a[temp]++;
        }
        num = 0;
        flag = 0;
        dfs(0, 0, 0);
        if (!flag)
            cout <<"No Solution"<< endl;
    }
}
//DP方法,01背包
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int dp[10010], w[10010];
//bool choice[10010][110];
//int cmp1(int a, int b){return a > b;}
//int main() {
//    int n, m;
//    scanf("%d%d", &n, &m);
//    for(int i = 1; i <= n; i++)
//        scanf("%d", &w[i]);
//    sort(w + 1, w + n + 1, cmp1);
//    for(int i = 1; i <= n; i++) {
//        for(int j = m; j >= w[i]; j--) {
//            if(dp[j] <= dp[j-w[i]] + w[i]) {
//                choice[i][j] = true;
//                dp[j] = dp[j-w[i]] + w[i];
//            }
//        }
//    }
//    if(dp[m] != m) printf("No Solution");
//    else {
//        vector<int> arr;
//        int v = m, index = n;
//        while(v > 0) {
//            if(choice[index][v] == true) {
//                arr.push_back(w[index]);
//                v -= w[index];
//            }
//            index--;
//        }
//        for(int i = 0; i < arr.size(); i++) {
//            if(i != 0) printf(" ");
//            printf("%d", arr[i]);
//        }
//    }
//    return 0;
//}
