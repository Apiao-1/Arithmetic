//1142 maximal clique（25)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
int e[210][210],a[210];

int main(){
    int n,m,x,y;
    cin >> n>>m;
    for (int i = 1; i <= n; i++) e[i][i] = 1;
    for (int i = 0; i < m; i++)
    {
        cin >>x>>y;
        e[x][y] = e[y][x] = 1;
    }
    int k,p;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> p;
        for (int j = 1; j <= p; j++) cin >> a[j];
        int flag = 1,isPrint = 0;
        for (int j = 1; j <= p; j++){
            for (int k = 1; k <= p; k++){
                if (a[k]==a[j])continue;
                if (e[a[j]][a[k]] == 0)
                {
                    flag = 0;
                    break;
                }
            }
            if(flag == 0){
                isPrint = 1;
                cout << "Not a Clique"<<endl;
                break;
            }
        }
        if (isPrint)continue;
        for (int j = 1; j <= n; j++)
        {
            int tag = 1;
            for (int k = 1; k <= p; k++){
                if (a[k]==j){tag = 0;break;}
                if (e[j][a[k]] == 0){
                    tag = 0;
                    break;
                }
            }
            if (tag == 1 )
            {
                cout << "Not Maximal"<<endl;
                isPrint = 1;
                break;
            }
            
        }
        if (!isPrint) cout << "Yes"<<endl;
    }
    return 0;
}
