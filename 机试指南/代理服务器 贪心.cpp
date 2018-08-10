//https://www.nowcoder.com/practice/1284469ee94a4762848816a42281a9e0?tpId=40&tqId=21335&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

int main(){
    int n,m;
    while(scanf("%d",&n) !=EOF){
        char str1[1001][20],str2[5001][20];
        for(int i = 0 ;i<n;i++){
            scanf("%s",&str1[i][0]);
        }
        scanf("%d",&m);
        for(int i = 0 ;i<m;i++){
            scanf("%s",&str2[i][0]);
        }
        int x = 0;
        int max = 0,flag = 0,cnt = 0,seq = 0,rst = 0;
        if (n==1) {//服务器只有一台时需判断不可能的情况
            for (int i = 0; i<m; i++) {
                if(strcmp(str2[i],str1[0]) == 0){
                    cout << -1 << endl;
                    x= 0;
                    break;
                }
            }
            if (!x) {
                break;
            }
        }
        
        while(seq < m){
            cnt = max = 0;
            for(int i = 0;i<n;i++){//贪心，每次遍历服务器从当前序列起能走得最远的
                cnt = 0;
                for(int j = seq;j<m;j++){
                    if(strcmp(str2[j],str1[i]) != 0)
                        cnt++;
                    else
                        break;
                }
                if(cnt > max){
                    max = cnt;
                    flag = i;
                }
            }
            seq += max;
            if (seq >= m) {
                break;
            }
            rst ++;//切换服务器数+1
        }
        cout  << rst << endl;
        
    }
    
    return 0;
}
