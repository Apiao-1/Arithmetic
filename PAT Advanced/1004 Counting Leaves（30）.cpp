//1004 Counting Leaves（30） https://pintia.cn/problem-sets/994805342720868352/problems/994805521431773184
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> child[200];
int sum[200],maxNum;

void dfs(int id, int depth){
    if (maxNum < depth) {
        maxNum = depth;
    }
    int len = child[id].size();
    if (len == 0) {
        sum[depth]++;
    }else
        for (int i = 0; i<len; i++) {
            dfs(child[id][i],depth+1);
        }
}

int main() {
    int n,m,id,num,tmp,i;
    while (cin >> n) {
        fill(sum, sum+200, 0);
        if (n == 0) {
            break;
        }
        cin >> m;
        for (int i = 0; i<m; i++) {
            cin >> id >> num;
            for (int j = 0; j<num; j++) {
                cin >> tmp;
                child[id].push_back(tmp);
            }
        }
        dfs(1,0);
        for (i = 0; i<maxNum+1; i++) {
            if (i == 0) {
                cout << sum[i];
            }else
                cout << " "<< sum[i];
        }
        cout << endl;
    }
    return 0;
}
