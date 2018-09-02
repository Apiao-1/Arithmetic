//1109 Group Photo
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
#include <set>
#include <string.h>
using namespace std;
int ans[12][10010];

struct people{
    char name[12];
    int height;
}p[10010];

bool cmp(people a, people b){
    if (a.height != b.height) {
        return a.height > b.height;
    }else
        return strcmp(a.name, b.name) < 0;
}

int main(){
    int n,row,num,ind = 0,j;
    scanf("%d%d",&n,&row);
    for (int i = 0; i<n; i++) {
        scanf("%s %d",p[i].name,&p[i].height);
    }
    sort(p, p+n, cmp);
    for (int i =0; i<row; i++) {
        if (i == 0) {
            num =n/row + n%row;
        }else
            num =n/row;
        int pos = num / 2 + 1,tag = 1;
        ans[i][pos] = ind++;
        for (int j = 1; j<num; j++) {
            if (j % 2 == 1) {
                ans[i][pos-tag] = ind++;
            }else{
                ans[i][pos+tag] = ind++;
                tag++;
            }
            
        }
    }
    for (int i =0; i<row; i++) {
        if (i == 0) {
            num =n/row + n%row;
        }else
            num = n/row;
        for (j = 1; j<num; j++) {
            printf("%s ",p[ans[i][j]].name);
        }
        printf("%s\n",p[ans[i][j]].name);
    }
    
    return 0;
}
