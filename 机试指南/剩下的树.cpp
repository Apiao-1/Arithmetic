//https://www.nowcoder.com/practice/f5787c69f5cf41499ba4706bc93700a2?tpId=40&tqId=21356&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
using namespace std;
int a[10001];
int main(){
    int l,m,s,e,cnt;
    while (cin >> l>>m) {
        cnt = 0;
        for (int i = 0; i<=l; i++) {
            a[i] = 1;
        }
        for (int i = 1; i<=m; i++) {
            cin >> s >> e;
            for(int j = s;j<=e;j++)
                a[j] = 0;
        }
        for (int i = 0; i<=l; i++) {
            if(a[i] == 1)
                ++cnt;
        }
        cout << cnt << endl;
        
    }
    return 0;
}
