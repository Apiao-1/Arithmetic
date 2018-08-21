//1098 Insertion or Heap Sort https://pintia.cn/problem-sets/994805342720868352/problems/994805435700199424
//此题需手动模拟堆排序的排序过程，因为queue不支持遍历操作，无法输出一次操作后每个节点的情况
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
#include <set>
using namespace std;
int b[110];

void downSort(int low,int high){
    int i = low,j = 2*i;
    while (j <= high) {
        if (j +1 <=high && b[j] < b[j+1]) {
            j = j+1;
        }
        if (b[j] > b[i]) {
            swap(b[j], b[i]);
            i = j;//大顶堆是从上往下换，不是i++
            j = 2*i;
        }else
            break;//做单次即可，注意此处一定要加break，否则会有死循环
    }
}

int main(){
    int n,a[110],num1 = 0,num2 = 0,flag = 0,i;
    scanf("%d",&n);
    for (int i =1; i<=n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i =1; i<=n; i++) {
        scanf("%d",&b[i]);
    }
    for (int i =2; i<=n; i++) {
        if (b[i] >= b[i-1]) {
            num1++;
        }else
            break;
    }
    for (int i =n; i>0; i--) {
        if (b[i] > b[i-1] && b[i] > b[1]) {//若仅仅写成b[i] > b[i-1]的话不同的case会有误差
            num2++;
        }else
            break;
    }
    if (num1 > num2) {
        printf("Insertion Sort\n");
        sort(b+1, b+num1+3);
    }else{
        printf("Heap Sort\n");
        swap(b[1], b[n-num2]);
        downSort(1,n - num2 -1);
    }
    for (i =1; i<n; i++) {
        printf("%d ",b[i]);
    }
    printf("%d\n",b[i]);
    return 0;
}

