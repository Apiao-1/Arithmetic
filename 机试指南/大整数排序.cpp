//https://www.nowcoder.com/practice/b744af632ac4499aa485d7bb048bb0aa?tpId=40&tqId=21556&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
using namespace std;

struct node {
    string val;
    int len;
};

bool cmp(node a ,node b){
    if (a.len != b.len) {
        return a.len < b.len;
    }else
        return a.val < b.val;
}

int main(){
    int n;
    while (cin >> n) {
        struct node point[n+1];
        for (int i = 0; i<n; i++) {
            cin >> point[i].val;
            point[i].len = point[i].val.length();
        }
        sort(point, point+n, cmp);
        for (int i = 0; i<n; i++) {
            cout << point[i].val << endl;
        }
    }
    return 0;
}
