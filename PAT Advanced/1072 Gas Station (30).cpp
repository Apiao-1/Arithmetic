//1072 Gas Station (30)https://pintia.cn/problem-sets/994805342720868352/problems/994805396953219072
//做n次Dijkstra，花了很长时间找到的bug1.答案错误时，第一步审题，第二步检查各处的初始化，例min，max，flag等的值2.切记，字符数组保存字符串时，一定要留一个空间保存结束符 '\0'（提示段错误），永远别把数组开得很极限
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <map>
using namespace std;
int n,m,e[1100][1100],visit[1100],dist[1100];

struct ans{
    int id;
    float min,avg;
}ans;

void dij(int s){
    for (int i = 1; i<=n+m; i++) {
        dist[i] = e[s][i];
    }
    dist[s] = 0;
    visit[s] = 1;
    for (int j = 1; j<=n+m; j++) {
        int min = 99999,flag = -1;//记得每次都要初始化最小值
        for (int i = 1; i<=n+m; i++) {
            if (!visit[i] && dist[i] < min) {
                min = dist[i];
                flag = i;
            }
        }
        if (flag == -1) {
            break;
        }
        visit[flag] = 1;
        for (int i = 1; i<=n+m; i++) {
            if (!visit[i] && dist[i] > dist[flag] + e[flag][i]) {
                dist[i] = dist[flag] + e[flag][i];
            }
        }
    }
}

int strtoint(char s1[]){
    int edge = 0,len = strlen(s1);
    if (s1[0] == 'G') {
        edge = s1[1] - '0';
        if (len > 2) {
            edge = 10*edge + s1[2] - '0';
        }
        edge += n;
    }else{
        for (int i = 0; i<len; i++) {
            edge = edge * 10 + s1[i] - '0';
        }
    }
    return edge;
}

int main(){
    int k,maxService,len;
    scanf("%d%d%d%d\n",&n,&m,&k,&maxService);
    int e1,e2,flag=0;
    ans.min = 0;
    char s1[4]="",s2[4]="";//这里花了最长的时间找bug，永远别把数组开的很极限！多开点空间！此处若输入三位数，当最后一个/0不够放时，会出现数据的错误（一直提示段错误）;
    //切记，字符数组保存字符串时，一定要留一个空间保存结束符 '\0'。
    fill(e[0], e[0]+1100*1100, 99999);
    for (int i = 0; i<k; i++) {
        scanf("%s%s%d",s1,s2,&len);
        e1 = strtoint(s1);
        e2 = strtoint(s2);
        if (e1 == e2) {
            e[e1][e2] = e[e2][e1] = 0;
        }
        if (len < e[e1][e2]) {//输入可能有重边的情况
            e[e1][e2] = len;
            e[e2][e1] = len;
        }
    }
    for (int j = 1; j<=m; j++) {
        int start = j+n;
        int judge = 1;
        float sum = 0;
        float min = 99999;//此处未初始化找了好久
        fill(visit, visit+1100, 0);
        fill(dist, dist+1100, 99999);
        dij(start);
        for (int i = 1; i<=n; i++) {
            sum += dist[i];
            if (dist[i] > maxService) {
                judge = 0;
                break;
            }
            if (dist[i] < min) {
                min = dist[i];
                flag = i;
            }
        }
        if (judge && min > ans.min) {
            ans.min = min;
            ans.id = j;
            ans.avg =sum/n;
        }else if(judge && min == ans.min){
            if (ans.avg > sum/n) {
                ans.min = min;
                ans.id = j;
                ans.avg =sum/n;
            }
        }
    }
    if (ans.id == 0) {
        printf("No Solution\n");
    }else{
        printf("G%d\n",ans.id);
        printf("%.1f %.1f\n",ans.min,ans.avg);
    }
    return 0;
}
