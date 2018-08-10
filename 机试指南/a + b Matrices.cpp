//https://www.nowcoder.com/profile/2575579/codeBookDetail?submissionId=28580201
#include <iostream>
using namespace std;
int main(){
    int m,n,a[1001][1001],b[1001][1001],i,j,cnt,flag;
    while (cin >> m) {
        if (m == 0) {
            break;
        }
        cin >> n;
        cnt = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        for (i = 0; i < m; i++) {
            flag = 1;
            for (j = 0; j < n; j++) {
                cin >> b[i][j];
                b[i][j] = a[i][j] + b[i][j];
                if (b[i][j]) {
                    flag = 0;
                }
            }
            if (flag) {
                cnt ++;
            }
        }
        for (i = 0; i < n; i++) {
            flag = 1;
            for (j = 0; j < m; j++) {
                if (b[j][i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cnt ++;
            }
        }
        cout << cnt << endl;
        
    }
    return 0;
}


