//1055 The World's Richest（25）https://pintia.cn/problem-sets/994805342720868352/problems/994805421066272768
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
using namespace std;
struct Person{//存储相应信息的结构体
    char name[9];
    int age,worth;
}person[100010];
bool cmp(Person p1,Person p2){//比较函数
    if(p1.worth!=p2.worth)
        return p1.worth>p2.worth;
    else if(p1.age!=p2.age)
        return p1.age<p2.age;
    else
        return strcmp(p1.name,p2.name)<0;
}

int main(){
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;++i)
        scanf("\n%s%d%d",person[i].name,&person[i].age,&person[i].worth);
    sort(person,person+N,cmp);//排序
    for(int i=1;i<=K;++i){
        int M,Amin,Amax;
        bool f=false;
        scanf("%d%d%d",&M,&Amin,&Amax);
        printf("Case #%d:\n",i);
        for(int j=0;j<N&&M>0;++j)//遍历数组
            if(person[j].age>=Amin&&person[j].age<=Amax){//找到符合要求的人
                printf("%s %d %d\n",person[j].name,person[j].age,person[j].worth);//输出
                --M;//将M递减
                f=true;//表示已输出过
            }
        if(!f)//在该年龄段没有任何输出
            printf("None\n");//输出None
    }
    return 0;
}
