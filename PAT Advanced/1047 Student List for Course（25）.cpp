////1047 Student List for Course（25）https://pintia.cn/problem-sets/994805342720868352/problems/994805433955368960
//直接用string去写，最后一组测试用例会运行超时，故用char类型
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string.h>
//using namespace std;
//vector<string> course[2510];
//
//int main() {
//    int n, k;
//    string name;
//    scanf("%d %d", &n, &k);
//    for(int i = 0; i < n; i++) {
//        int cnt, temp;
//        cin >> name >> cnt;
//        for(int j = 0; j < cnt; j++) {
//            scanf("%d", &temp);
//            course[temp].push_back(name);
//        }
//    }
//    for(int i = 1; i <= k; i++) {
//        printf("%d %d\n", i, course[i].size());
//        sort(course[i].begin(), course[i].end());
//        for(int j = 0; j < course[i].size(); j++)
//            cout << course[i][j] << endl;
//    }
//    return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
char name[40010][5];
vector<int> course[2510];
bool cmp1(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        int cnt, temp;
        scanf("%s %d", name[i], &cnt);
        for(int j = 0; j < cnt; j++) {
            scanf("%d", &temp);
            course[temp].push_back(i);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp1);
        for(int j = 0; j < course[i].size(); j++)
            printf("%s\n", name[course[i][j]]);
    }
    return 0;
}
