// 1133 Splitting A Linked List https://pintia.cn/problem-sets/994805342720868352/problems/994805346776760320
//该题需注意1.链表结构的存储用数组会大大提高写代码的效率；2.注意最后的输出，小技巧（题意要求每一个节点的next节点都指向新的节点，只需把下一个节点的当前位置输出两遍即可，无需更改真实的指向）
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
using namespace std;

struct node{
    int val,next;
}list[100001];

int main(){
    vector<int> vec[3];
    int loc,ori,n,k;
    cin >> ori;
    while (cin >> n >> k) {
        for (int i = 0; i<n; i++) {
            cin >> loc;
            cin >> list[loc].val >> list[loc].next;
        }
        loc = ori;
        while (loc != -1) {
            int val = list[loc].val;
            if (val < 0) {
                vec[0].push_back(loc);
            }else if(val <= k){
                vec[1].push_back(loc);
            }else
                vec[2].push_back(loc);
            loc = list[loc].next;
        }
        int flag = 1;
        for (int i = 0; i<3; i++) {
            for (int j=0; j<vec[i].size(); j++) {
                if (flag) {
                    printf("%05d %d ",vec[i][j],list[vec[i][j]].val);
                    flag = 0;
                }else
                    printf("%05d\n%05d %d ",vec[i][j],vec[i][j],list[vec[i][j]].val);
            }
        }
        printf("-1\n");

    }
    return 0;
}
