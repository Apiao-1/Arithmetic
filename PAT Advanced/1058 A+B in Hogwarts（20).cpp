//1058 A+B in Hogwarts（20） https://pintia.cn/problem-sets/994805342720868352/problems/994805416519647232
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> child[200];
int sum[200],maxNum;

int main(){
    int a1,b1,c1,a2,b2,c2,a3,b3,c3;
    scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
    a3 = a1+a2;
    b3 = b1+b2;
    c3 = c1+c2;
    if (c3 >= 29 ) {
        c3 -= 29;
        b3++;
    }
    if (b3 >= 17) {
        b3 -= 17;
        a3++;
    }
    printf("%d.%d.%d\n",a3,b3,c3);
    return 0;
}
