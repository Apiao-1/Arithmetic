//1014 Waiting in Line (30) https://pintia.cn/problem-sets/994805342720868352/problems/994805498207911936
//反思没把bug找出来的原因，1.忽略了题目中的“如果这个服务已经开始了，无论时间多长都要等他服务完毕”一条件；2.注意到该条件后，最后判断是否在17点以前开始任务不应减去cost[i]进行判断（cost[i]在过程中就已被改变，故需在开始新设一个数组）3.在初始化排队时，没注意到无法把n个窗口都排满的情况（注意到了在黄线内未排满，但忽略了人太少以致窗口都排不满)
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>
using namespace std;

int main(){
    int n,m,k,query,i,curTime = 0,j;
    int cost[1010],ans[1010],time[1010];
    scanf("%d%d%d%d",&n,&m,&k,&query);
    for (i = 1; i<=k; i++) {
        scanf("%d",&cost[i]);
        time[i] = cost[i];
    }
    queue<int> q[n];
    int num = 1;
    for (int i = 1; i<=m; i++) {
        for (int j = 0; j<n; j++) {
            if (num <= k) {//此处要注意初始化时队伍就排不满的情况
                q[j].push(num);
                num++;
            }
        }
    }
    
    int tmp,min = 9999,flag = 0,pnum = 0;
    i = 0;
    while (i < k) {
        min = 9999;
        for (j = 0; j<n; j++) {
            if (q[j].size() > 0) {
                tmp = q[j].front();
                if (cost[tmp] < min) {
                    min = cost[tmp];
                    flag = j;//窗口号
                    pnum = tmp;//顾客号
                }
            }
        }
        curTime += min;
        ans[pnum] = curTime;
        q[flag].pop();
        if (num <= k) {
            q[flag].push(num++);
        }
        for (j = 0; j<n; j++) {
            if (j != flag && q[j].size() > 0) {
                cost[q[j].front()] -= min;
            }
        }
        i++;
    }
    int queryNum,h,minute;
    for (int i = 0; i<query; i++) {
        scanf("%d",&queryNum);
        tmp = ans[queryNum];
        h = tmp / 60;
        minute = tmp % 60;
        if (ans[queryNum] - time[queryNum] < 540) {
            printf("%02d:%02d\n",8+h,minute);
        }else {
            printf("Sorry\n");
        }
    }
    return 0;
}
