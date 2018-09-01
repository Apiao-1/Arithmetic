//1089 Insert or Merge（25)
//参考了牛客网上的思路写的归并排序，写法很漂亮
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <math.h>
#include <map>
using namespace std;
int a[120],b[120],n;

void mergeSort(){
    int step = 1,i,j,flag = 1;
    while (flag) {
        flag = 0;
        for (j = 0; j<n; j++) {
            if (b[j] != a[j]) {
                flag = 1;
            }
        }
        step *= 2;
        for (i = 0; i < n; i+=step) {
            sort(a+i, a+min(i+step,n));//此处需特别注意当i+step>n时会报错
        }
    }
    
}

int main(){
    int i,j;
    cin >> n;
    for (i = 0; i<n; i++) {
        cin >> a[i];
    }
    for (i = 0; i<n; i++) {
        cin >> b[i];
    }
    for (i = 0; i< n-1; i++) {
        if (b[i] > b[i+1]) {//此处若写成>=则会报段错误
            break;
        }
    }
    for (j = i+1; j<n; j++) {
        if (b[j] != a[j]) {
            break;
        }
    }
//    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
//    for (j = i + 1; a[j] == b[j] && j < n; j++);
    
    if (j == n) {
        cout <<"Insertion Sort" << endl;
        sort(a, a+i+2);
    }else{
        cout <<"Merge Sort" << endl;
        mergeSort();
    }
    for (i = 0; i<n; i++) {
        if (i == 0) {
            cout << a[i];
        }else
            cout << " "<< a[i];
    }
    cout << endl;
    return 0;
}

//#include <algorithm>
//#include <iostream>
//using namespace std;
//int n,a[110],s[110];
//void mergesort(int (&a)[110],int s[],int n){   //注意引用数组的写法
//    int step=1,flag=1;
//    while(flag){                               //flag表示数组的中间步骤是否与中间数组相同
//        flag=0;
//        for(int i=0;i<n;i++){
//            if(a[i]!=s[i])
//                flag=1;
//        }
//        step*=2;                              //不断的归并排序，直到与中间数组相同，再排序一次并退出
//        for(int i=0;i<n;i+=step)
//            sort(a+i,a+min(i+step,n));        //不像插入排序一样只用一次处理。是因为判断归并的有序 区间大小比较复杂
//    }
//}
//int main(){
//    int i,j;
//    cin>>n;
//    for(i=0;i<n;i++)
//        cin>>a[i];
//    for(i=0;i<n;i++)
//        cin>>s[i];
//    for (i = 0; i < n - 1 && s[i] <= s[i + 1]; i++);  //找出中间数组的有序部分
//    for (j = i + 1; a[j] == s[j] && j < n; j++);      //判断排序类型
//    if(j==n){
//        cout<<"Insertion Sort"<<'\n';
//        sort(a,a+i+2);                      //直接用sort函数代替插入排序（注意下标）
//    }
//    else{
//        cout<<"Merge Sort"<<'\n';
//        mergesort(a,s,n);
//    }
//    for(int i=0;i<n;i++){
//        cout<<a[i];
//        if(i!=n-1) cout<<" ";
//    }
//    return 0;
//}
