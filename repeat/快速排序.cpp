//快速排序
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <math.h>
#include <climits>
#include <vector>
using namespace std;
int a[1001];

void quicksort(int start,int end){
    int i = start;
    int j = end;
    int tmp = a[start];//基准点每次选取第一个元素
    while (i < j) {//单趟快速排序
        while (i < j && a[j] >= tmp)j--;
        if (i < j)a[i++] = a[j];
        while (i < j && a[i] <= tmp)i++;
        if (i < j)a[j--] = a[i];
    }
    a[i] = tmp;
    if (start < i-1) quicksort(start, i-1);
    if (end > j+1) quicksort(j+1, end);
        
}

int main(){
    int n;
    while (cin >> n) {
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        quicksort(0,n-1);
        for (int i=0; i<n; i++) {
            cout << a[i];
        }
    }
    return 0;
}
