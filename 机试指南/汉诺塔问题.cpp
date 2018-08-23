//汉诺塔问题
//递归实现,An = 2An-1 + 1
//https://www.cnblogs.com/dmego/p/5965835.html
#include <iostream>
using namespace std;
int a[65];
int i = 0;

void move(int disks , char A,char B){
    cout << "第" << ++i << "次移动将第" << disks << "号圆盘从" << A <<"移至" << B <<endl;
}

//只计算移动次数
void moveTime(int n){
    if (n==1){
        a[1] = 1;
    }else{
        moveTime(n-1);
        a[n] = 2*a[n-1] +1;
    }
}

//输出移动路径
void hanoi(int n, char A, char B,char C){//C为辅助塔，把n个圆盘从A移至B
    if (n==1){
        a[1] = 1;
        move(1,A,B);
    }else{
        hanoi(n-1, A, C, B);
        move(n, A, B);
        hanoi(n-1, C, B, A);
    }
}

int main(){
    int n;
    cin >> n;
    a[1] = 1;
//    moveTime(n);
//    cout << a[n] <<endl;
    hanoi(n, 'A', 'C', 'B');
    cout << i <<endl;
    return 0;
}
