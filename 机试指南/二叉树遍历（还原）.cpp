//https://www.nowcoder.com/practice/6e732a9632bc4d12b442469aed7fe9ce?tpId=40&tqId=21544&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
char pre[31],mid[31],aft[31];//分别存放前序/中序/后序 序列

void find_by_pre_mid(int s1,int e1,int s2,int e2,int s3,int e3){//s1,e1为前序的起始/终止下标，依次类推
    if (s3 > e3) {
        return ;
    }
    char c = pre[s1];
    int i = 0;
    aft[e3] = c;
    while (mid[s2+i] != c) {
        i++;
    }
    find_by_pre_mid(s1+1, s1+i, s2, s2+i-1, s3, s3+i-1);//除第一位外起始地址均为自身，结束地址所有多为i-1
    find_by_pre_mid(s1+i+1, e1, s2+i+1, e2, s3+i, e3-1);
    return ;
}

int main(){
    int len1,len2,len3;
    while (cin >> pre >> mid) {
        len1 = (int)strlen(pre);
        len2 = (int)strlen(mid);
        len3 = len1;
        find_by_pre_mid(0,len1-1,0,len2-1,0,len3-1);
        cout << aft << endl;
    }
    
    
    return 0;
}
