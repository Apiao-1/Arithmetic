//1067 Sort with Swap(0,*) (25) https://pintia.cn/problem-sets/994805342720868352/problems/994805403651522560
//1.存储时为避免找数字的位置时每次都要从头遍历一遍，直接存储数字的位置（类似哈希表）；2.0换到原位时，判断下一个不在位置上的数字用一个index存储，因为以前寻找的在之后一定还是有序的
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[100011];

int main() {
    int n,cnt = 0,ans = 0,loc = 0,j,num,index = 0;
    scanf("%d", &n);
    for (int i = 0; i<n; i++) {
        scanf("%d",&num);
        a[num] = i;
        if (a[num] != num && num != 0) {//注意此处要去除0，因为最后一次归为一定是把0和一个数字回归原位，但cnt只-1
            cnt++;
        }
    }
    while (cnt > 0) {
        if (a[0]) {
            swap(a[0], a[a[0]]);
            ans++;
            cnt--;
        }else if(a[0] == 0){
            for (int i=index+1; i<n; i++) {
                if (a[i] != i) {
                    swap(a[0],a[i]);
                    ans++;
                    index = i;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    
    
    return 0;
}
