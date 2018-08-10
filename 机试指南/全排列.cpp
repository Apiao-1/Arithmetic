//https://www.nowcoder.com/practice/5632c23d0d654aecbc9315d1720421c1?tpId=40&tqId=21374&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
char c[7],ans[7];
int len,mark[7];

void dfs(int i){
    if(i == len){
        for (int k = 0; k<len; k++) {
            cout << ans[k];
        }
        cout << endl;
        return ;
    }
    for (int j = 0; j < len; j++) {
        if (!mark[j]) {
            ans[i] = c[j];
            mark[j] =1;
            dfs(i+1);
            mark[j] = 0;
        }
    }
}


int main()
{
    while (cin >> s) {
        len = int(s.length());
        memset(mark, 0, sizeof(mark));
        for (int i = 0; s[i]; i++) {
            c[i] = s[i];
        }
        sort(c, c+len);
        dfs(0);//从第一位开始dfs
        cout << endl;
        
        
        
        
    }
    
    
    return 0;
}
