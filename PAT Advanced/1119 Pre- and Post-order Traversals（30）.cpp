//1119 Pre- and Post-order Traversals（30）https://pintia.cn/problem-sets/994805342720868352/problems/994805353470869504
//前序后序转中序
#include <iostream>
#include <vector>
using namespace std;
vector<int> in;
int pre[40],post[40];
bool Unique = true;

void getIn(int s1,int e1,int s3,int e3) {
    if (s1 == e1) {
        in.push_back(pre[s1]);
        return ;
    }
    if (pre[s1] == post[e3]){
        int x = 1;
        while (pre[s1+x] != post[e3 - 1]) {
            x++;
        }
        if (x > 1) {
            getIn(s1+1, s1 +x-1, s3, s3+x-2);
        }else//只有一个节点就无法确认是左子树还是右子树，此处把它当做右子树处理
            Unique = 0;
        in.push_back(post[e3]);
        getIn(s1+x, e1, s3+x-1, e3-1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    getIn(0, n-1, 0, n-1);
    printf("%s\n%d", Unique == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    printf("\n");
    return 0;
}
